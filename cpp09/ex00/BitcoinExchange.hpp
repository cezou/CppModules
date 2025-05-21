#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP

# include "../utils.hpp"
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>
# include <deque>
# include <fstream>
# include <iostream>
# include <string>
# include <map>
# include <ctime>

# define DATA_FILE "data.csv"

/**
 * @brief Class to represent the Bitcoin exchange
 * @details The class stores the exchange rate for each date in a map.
 * It reads the data from data.csv and stores it in a map.
 * It reads the input file and displays the exchange,
 *   finding the corresponding closest date in the map.
 */
class BitcoinExchange
{
public:
	BitcoinExchange(const char *filename);
	~BitcoinExchange() {};

	void storeData();
	void skipHeader(std::ifstream &data, std::string &line, size_t &line_nb);
	std::pair<std::string, double> parseLine(std::string line);

	void displayExchangeResults();
	std::pair<std::string, double> parseInputLine(std::string line);
	void findAndDisplayRate(const std::pair<std::string, double>& input);
	void displayOneExchangeResult(std::pair<std::string, double> input, double rate);


private:
	std::map<std::string, double> _rate;
	std::pair<std::string, double> _firstDate;
	std::string _filename;
	std::ifstream _file;

	// Not used but respects the rule of 5
	BitcoinExchange() {};
	BitcoinExchange(const BitcoinExchange& o) { (void)o; };
	BitcoinExchange& operator=(const BitcoinExchange& o) { (void)o; return *this; };
};


/** 
 * @brief Class to represent a date and check its validity
 * @details A date is valid if:
 * - Is in the format YYYY-MM-DD
 * - The year is a positive integer
 * - The month is between 1 and 12
 * - The day is >= 1 and <= 31 and correct for the month
 *    - Example: 
 *      January has 31 days, April has 30, February has 28 or 29 depending on leap year
 * - The date is not in the future
 */
class Date
{
public:
	Date(std::string date);

	inline void checkDate();
	inline void checkFebruary();
	inline void checkDateintheFuture();

private:

	std::string _date;
	int _year;
	int _month;
	int _day;

	// Not used but respects the rule of 5
	Date() {}
	Date(const Date& o) {(void)o; }
	Date& operator=(const Date& o) { (void)o; return *this; }

};

inline bool isLeapYear(int year)
{
	return (!(year % 4) && (year % 100)) || !(year % 400);
}

#endif