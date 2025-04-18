NAME = intern

OBJDIR = .objs
INCDIR = includes
SRCDIR = srcs
SRCS = main.cpp \
	$(SRCDIR)/Bureaucrat.cpp \
	$(SRCDIR)/AForm.cpp \
	$(SRCDIR)/ShrubberyCreationForm.cpp \
	$(SRCDIR)/RobotomyRequestForm.cpp \
	$(SRCDIR)/PresidentialPardonForm.cpp \
	$(SRCDIR)/Intern.cpp
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -I$(INCDIR) -I..

all: $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re