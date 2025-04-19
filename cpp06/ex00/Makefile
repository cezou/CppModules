NAME = convert

OBJDIR = .objs
INCDIR = includes
SRCDIR = srcs
SRCS = main.cpp \
	$(SRCDIR)/ScalarConverter.cpp
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))

# Define marker files
MODE_NORMAL = $(OBJDIR)/.normal_mode
MODE_LIMIT = $(OBJDIR)/.limit_mode

# Determine PRINT_LIMITS based on mode file existence at the start
PRINT_LIMITS := 1
ifneq ($(wildcard $(MODE_LIMIT)),)
PRINT_LIMITS := 0
endif

CC = c++
# Base CFLAGS without PRINT_LIMITS
CFLAGS_BASE = -Wall -Wextra -Werror -std=c++98 -g -I$(INCDIR) -I..
# CFLAGS for main.o including PRINT_LIMITS
CFLAGS_MAIN = $(CFLAGS_BASE) -DPRINT_LIMITS=$(PRINT_LIMITS)
# CFLAGS for other objects (if any)
CFLAGS_OTHER = $(CFLAGS_BASE)

# Default target depends on normal mode and the final executable
all: $(MODE_NORMAL) $(NAME)

# 'lim' target depends on limit mode and the final executable
lim: $(MODE_LIMIT) $(NAME)

# Rule to build the final executable, depends only on objects
# Use CFLAGS_MAIN for linking to ensure consistency, though base might also work
$(NAME): $(OBJS)
	@echo "Linking $(NAME) with PRINT_LIMITS=$(PRINT_LIMITS)..."
	$(CC) $(CFLAGS_MAIN) -o $(NAME) $(OBJS)

# Rule to switch to/ensure normal mode
# Cleans ONLY main.o and executable if switching FROM limit mode
$(MODE_NORMAL):
	@if [ -f $(MODE_LIMIT) ]; then \
		echo "Switching to normal mode (PRINT_LIMITS=0). Cleaning main.o and executable..."; \
		rm -f $(MODE_LIMIT) $(OBJDIR)/main.o $(NAME); \
	fi
	@mkdir -p $(OBJDIR)
	@touch $(MODE_NORMAL)

# Rule to switch to/ensure limit mode
# Cleans ONLY main.o and executable if switching FROM normal mode
$(MODE_LIMIT):
	@if [ -f $(MODE_NORMAL) ]; then \
		echo "Switching to limit mode (PRINT_LIMITS=1). Cleaning main.o and executable..."; \
		rm -f $(MODE_NORMAL) $(OBJDIR)/main.o $(NAME); \
	fi
	@mkdir -p $(OBJDIR)
	@touch $(MODE_LIMIT)

# Object compilation rules
# main.o uses CFLAGS_MAIN
$(OBJDIR)/main.o: main.cpp $(INCDIR)/ScalarConverter.hpp ../Utils.hpp
	@mkdir -p $(OBJDIR)
	@echo "Compiling main.cpp with PRINT_LIMITS=$(PRINT_LIMITS)..."
	$(CC) $(CFLAGS_MAIN) -c main.cpp -o $@

# ScalarConverter.o uses CFLAGS_OTHER (base flags)
$(OBJDIR)/ScalarConverter.o: $(SRCDIR)/ScalarConverter.cpp $(INCDIR)/ScalarConverter.hpp ../Utils.hpp
	@mkdir -p $(OBJDIR)
	@echo "Compiling ScalarConverter.cpp (no PRINT_LIMITS needed)..."
	$(CC) $(CFLAGS_OTHER) -c $(SRCDIR)/ScalarConverter.cpp -o $@

# Clean rules
clean:
	@echo "Cleaning object directory and mode files..."
	rm -rf $(OBJDIR)

fclean: clean
	@echo "Cleaning executable..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lim