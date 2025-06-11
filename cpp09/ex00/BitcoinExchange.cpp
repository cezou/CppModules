#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange(const char *filename) :  _filename(filename), _file(filename)
{
	if (!_file.is_open())
		throw RedException("Could not open file: " + _filename);
	storeData();
	displayExchangeResults();
}

/**
 * @brief Stores the data from data.csv
 * @details The function reads data.csv line by line and stores the date and rate
 *   in a map. It uses the date as the key and the rate as the value.
 *   It checks if each input line is valid.
 * @throw LineException if the header is invalid or if a line is invalid
 * If there is an error in data.csv,
 *   it will throw an exception and stop processing.
 */
void BitcoinExchange::storeData()
{
	std::ifstream data(DATA_FILE);
	if (!data.is_open())
		throw RedException("Could not find data file (data.csv)");

	std::string line;
	size_t line_nb = 0;
	skipHeader(data, line, line_nb);
	
	while (getlineIt(data, line, &line_nb))
	{
		if (line.empty())
			continue;
		try {
			std::pair<std::string, double> rate = parseLine(line);
			_rate[rate.first] = rate.second;
		}
		catch (const std::exception& e)
		{
			throw LineException(e.what(), line_nb, DATA_FILE);
		}
	}
}

void BitcoinExchange::skipHeader(std::ifstream &data, std::string &line, size_t &line_nb)
{
	if (!getlineIt(data, line, &line_nb))
		throw RedException(DATA_FILE " is empty");
	if (trim(line) != "date,exchange_rate")
		throw LineException("Invalid header", line_nb, DATA_FILE);
	if (!getlineIt(data, line, &line_nb))
		throw RedException(DATA_FILE " is empty");
	try {
		_firstDate = parseLine(line);
	}
	catch (const std::exception& e)
	{
		throw LineException(e.what(), line_nb, DATA_FILE);
	}
}

/**
 * @brief Parse a line of the data file
 * @details The function splits the line into date and rate
 *   and checks if the rate and date are valid.
 * @throw LineException if the line is invalid
 */
std::pair<std::string, double> BitcoinExchange::parseLine(std::string line)
{
	size_t comma_pos = line.find(',');
	if (comma_pos == std::string::npos)
		throw std::runtime_error("Invalid data format: < 2 fields");

	std::string date = trim(line.substr(0, comma_pos));
	Date d(date);

	std::string rate_str = trim(line.substr(comma_pos + 1));
	std::istringstream iss(rate_str);
	double rate;
	if (!(iss >> rate) || iss.peek() != EOF)
		throw std::runtime_error("Invalid rate format");
	return std::make_pair(date, rate);
}

/**
 * @brief Find the exchange rate for the given date
 * @details The function uses lower_bound to find the closest lower date in the data file
 *   corresponding to the input date.
 * @throw LineException if the date is before the first date in the data file 
 *   (exchange is impossible)
 */
void BitcoinExchange::findAndDisplayRate(const std::pair<std::string, double>& input)
{
	if (input.first < _firstDate.first)
		throw std::runtime_error("Date is before first date in data file");

	std::map<std::string ,double>::iterator rate = _rate.lower_bound(input.first);
	if (rate != _rate.begin())
	{
		if (rate->first != input.first)
			rate--;
		displayOneExchangeResult(input, rate->second);
	}
	else
		displayOneExchangeResult(input, _firstDate.second);
}


std::pair<std::string, double> BitcoinExchange::parseInputLine(std::string line)
{
	size_t sep_pose = line.find(" | ");
	if (sep_pose == std::string::npos)
		throw std::runtime_error("bad input => " + line);

	std::string date = trim(line.substr(0, sep_pose));
	Date d(date);

	std::string rate_str = trim(line.substr(sep_pose + 3));
	std::istringstream iss(rate_str);
	double rate;
	if (!(iss >> rate) || iss.peek() != EOF)
		throw std::runtime_error("Invalid rate format");
	if (rate < 0)
		throw std::runtime_error("not a positive number");
	if (rate > 1000)
		throw std::runtime_error("too large number (> 1000)");
	return std::make_pair(date, rate);
}

/**
 * @brief Display the exchange results
 * @details The function reads the input file line by line and displays each exchange
 * To find the exchange rate,
 *   it uses lower_bound to find the closest lower date in the data file
 *   corresponding to the input date.
 * @throw LineException if the header is invalid
 * If there is an error in the input file,
 *   it will display the error message
 *   but continues processing the remaining lines.
 */
void BitcoinExchange::displayExchangeResults()
{
	std::string line;
	size_t line_nb = 0;
	getlineIt(_file, line, &line_nb);
	if (trim(line) != "date | value")
		throw LineException("Invalid header", line_nb, _filename);

	while (getlineIt(_file, line, &line_nb))
	{
		if (trim(line).empty())
			continue;
		try {
			std::pair<std::string, double> input = parseInputLine(line);
			findAndDisplayRate(input);
		}
		catch (const std::exception& e)
		{
			std::cerr << LineException(e.what(), line_nb, _filename).what() << std::endl;
			continue;
		}
	}
}

/**
 * @brief Display the the exchange
 * @param input The input date and value
 * @param rate The exchange rate for the date
 */
void BitcoinExchange::displayOneExchangeResult(std::pair<std::string, double> input, double rate)
{
	std::cout	<< input.first << " => " << input.second << " = " 
				<< rate * input.second << std::endl;
}



Date::Date(std::string date) : _date(date)
{
	checkDate();
	std::istringstream yearStream(_date.substr(0, 4));
	yearStream >> _year;
	std::istringstream monthStream(_date.substr(5, 2));
	monthStream >> _month;
	std::istringstream dayStream(_date.substr(8, 2));
	dayStream >> _day;

	if (_year < 0)
		throw std::runtime_error("Invalid year");
	if (_month < 1 || _month > 12)
		throw std::runtime_error("Invalid month");
	if (_day < 1 || _day > 31)
		throw std::runtime_error("Invalid day");
	if ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && _day > 30)
		throw std::runtime_error("Invalid day for the month");
	if (_month == 2)
		checkFebruary();
	checkDateintheFuture();
}

/**
 * @brief Check if the date is in the correct format 
 * @details A Correct format is YYYY-MM-DD and contains only digits
 */
void Date::checkDate()
{
	if (_date.length() != 10 || _date[4] != '-' || _date[7] != '-')
		throw std::runtime_error("Invalid date format: Year-Month-Day");
	for (size_t i = 0; i < _date.length(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(_date[i]))
			throw std::runtime_error("Invalid character in date");
	}
}

/**
 * @brief Check if the year is a leap year
 */
void Date::checkFebruary()
{
	if (!isLeapYear(_year) && _day > 28)
		throw std::runtime_error("Invalid day for February in a non-leap year");
	else if (_day > 29)
		throw std::runtime_error("Invalid day for February in a leap year");
}

/**
 * @brief Check if the date is in the future
 */
void Date::checkDateintheFuture()
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	if (_year > (now->tm_year + 1900) || 
		(_year == (now->tm_year + 1900) && _month > (now->tm_mon + 1)) ||
		(_year == (now->tm_year + 1900) && _month == (now->tm_mon + 1) && _day > now->tm_mday))
		throw std::runtime_error("Date is in the future");
}
