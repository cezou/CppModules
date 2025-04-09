NAME = cpp04

OBJ_PATH = objs
SRC_PATH = srcs

SRC = Animal.cpp main.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
# SRC := $(addprefix $(SRC_PATH)/,$(SRC))

OBJ = $(patsubst %.cpp,$(OBJ_PATH)/%.o,$(SRC))

HEADERS = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g -I. -gdwarf-2

all: $(NAME)

$(OBJ_PATH)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : ${OBJ} ${HEADERS} Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re