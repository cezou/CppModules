NAME = identify_type

OBJDIR = .objs
SRCDIR = .
SRCS = main.cpp \
	Base.cpp
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))

CC = c++
# Simplified CFLAGS
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -I. -I..

# Default target
all: $(NAME)

# Rule to build the final executable
$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Object compilation rules using simplified CFLAGS
$(OBJDIR)/%.o: %.cpp Base.hpp ../Utils.hpp
	@mkdir -p $(OBJDIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rules
clean:
	@echo "Cleaning object directory..."
	rm -rf $(OBJDIR)

fclean: clean
	@echo "Cleaning executable..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re