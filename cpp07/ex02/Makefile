# --- Normal Build Variables ---
NAME = array
OBJDIR = .objs
SRCDIR = .
SRCS = main.cpp
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))

# --- Test Build Variables ---
TEST_NAME = array_test # Changed executable name
TEST_SRC = tests/main.cpp
# Use a different object file name for the test main to avoid conflicts
TEST_OBJS = $(addprefix $(OBJDIR)/, $(notdir $(TEST_SRC:.cpp=.test.o)))

CC = c++
# CFLAGS including include paths for current dir and parent dir (for utils.hpp)
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -I. -I..

# --- Targets ---

# Default target (normal build)
all: $(NAME)

# Rule to build the normal executable
$(NAME): $(OBJS)
	@echo Linking $(NAME)...
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Rule to build the test executable
test: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJS)
	@echo Linking $(TEST_NAME)...
	$(CC) $(CFLAGS) -o $(TEST_NAME) $(TEST_OBJS)

# --- Object Compilation Rules ---

# Rule for normal object file(s)
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp Array.hpp Array.tpp ../utils.hpp
	@echo Compiling $< for $(NAME)...
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for test object file
# Target uses the specific .test.o suffix
$(OBJDIR)/main.test.o: $(TEST_SRC) Array.hpp Array.tpp ../utils.hpp
	@echo Compiling $< for $(TEST_NAME)...
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# --- Clean Rules ---
clean:
	@echo Cleaning object files...
	rm -rf $(OBJDIR)

fclean: clean
	@echo Cleaning executables...
	rm -f $(NAME) $(TEST_NAME) # Updated to remove array_test

re: fclean all

test_re: fclean test # Add a re rule for test

.PHONY: all clean fclean re test test_re
