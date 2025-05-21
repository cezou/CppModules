# --- Normal Build Variables ---
NAME = btc
OBJDIR = .objs
SRCDIR = .
SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))

CC = c++
# CFLAGS including include paths for current dir and parent dir (for utils.hpp)
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -I. -I.. -gdwarf-2

# --- Targets ---

# Default target (normal build)
all: $(NAME)

# Rule to build the normal executable
$(NAME): $(OBJS)
	@echo Linking $(NAME)...
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# --- Object Compilation Rules ---

# Rule for main.cpp
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp BitcoinExchange.hpp ../utils.hpp
	@echo Compiling $< for $(NAME)...
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for BitcoinExchange.cpp
$(OBJDIR)/BitcoinExchange.o: $(SRCDIR)/BitcoinExchange.cpp BitcoinExchange.hpp ../utils.hpp
	@echo Compiling $< for $(NAME)...
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# --- Clean Rules ---
clean:
	@echo Cleaning object files...
	rm -rf $(OBJDIR)

fclean: clean
	@echo Cleaning executables...
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
