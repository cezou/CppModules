# --- Normal Build Variables ---
NAME = PmergeMe
OBJDIR = .objs
SRCS = main.cpp srcs/PmergeMe.cpp srcs/printUtils.cpp 
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))
HEADERS = includes/PmergeMe.hpp includes/IntC.hpp includes/printUtils.hpp ../utils.hpp

CC = c++
# Base CFLAGS including include paths for current dir, includes dir and parent dir (for utils.hpp)
CFLAGS = -Wall -Wextra -std=c++98 -g -I. -Iincludes -I.. -gdwarf-2

#color
BLUE = \033[34m
WHITE = \033[37m

# Marqueurs pour suivre le mode de compilation
DEBUG_MARKER = .debug_mode
NORMAL_MARKER = .normal_mode

# --- Targets ---

# Default target (normal build - PRINT=0)
all: $(NORMAL_MARKER) $(NAME)

# Cible pour définir le mode normal (PRINT=0)
$(NORMAL_MARKER):
	@if [ -f $(DEBUG_MARKER) ]; then \
		rm -rf $(OBJDIR); \
		rm -f $(DEBUG_MARKER); \
	fi
	@touch $(NORMAL_MARKER)
	@$(eval CFLAGS += -DPRINT=0)

# Cible pour le mode debug (PRINT=1)
debug: $(DEBUG_MARKER) $(NAME)

# Marqueur pour le mode debug
$(DEBUG_MARKER):
	@if [ -f $(NORMAL_MARKER) ]; then \
		rm -rf $(OBJDIR); \
		rm -f $(NORMAL_MARKER); \
	fi
	@touch $(DEBUG_MARKER)
	@$(eval CFLAGS += -DPRINT=1)
	@echo "$(BLUE)PmergeMe built in debug mode (PRINT=1)$(WHITE)"

# Rule to build the executable
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
	rm -f $(DEBUG_MARKER) $(NORMAL_MARKER)

fclean: clean
	@echo Cleaning executables...
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
