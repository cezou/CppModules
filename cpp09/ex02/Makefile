# --- Normal Build Variables ---
NAME = PmergeMe
OBJDIR = .objs
SRCS = main.cpp srcs/PmergeMe.cpp srcs/printUtils.cpp 
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))
HEADERS = includes/PmergeMe.hpp includes/IntC.hpp includes/printUtils.hpp ../utils.hpp

CC = c++
# CFLAGS including include paths for current dir, includes dir and parent dir (for utils.hpp)
CFLAGS = -Wall -Wextra -std=c++98 -g -I. -Iincludes -I.. -gdwarf-2

# --- Targets ---

# Default target (normal build)
all: $(NAME)

# Rule to build the normal executable
$(NAME): $(OBJS) $(HEADERS) Makefile
	@echo Linking $(NAME)...
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# --- Object Compilation Rules ---

# Rule for main.cpp
$(OBJDIR)/main.o: main.cpp $(HEADERS)
	@echo Compiling $< for $(NAME)...
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for files in srcs/
$(OBJDIR)/%.o: srcs/%.cpp $(HEADERS)
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
