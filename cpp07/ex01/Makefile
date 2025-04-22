NAME = templates

OBJDIR = .objs
SRCDIR = .
SRCS = main.cpp 
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))

CC = c++
# Simplified CFLAGS
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -I. -I..

# Default target
all: $(NAME)

# Rule to build the final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Object compilation rules using simplified CFLAGS
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp iter.hpp ../utils.hpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rules
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re