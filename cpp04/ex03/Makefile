NAME = cpp04

OBJ_PATH = .objs
SRC_PATH = srcs
INC_PATH = includes

SRC = AMateria.cpp Character.cpp MateriaSource.cpp Ice.cpp Cure.cpp
SRC := $(addprefix $(SRC_PATH)/,$(SRC))
SRC += main.cpp

OBJ = $(patsubst $(SRC_PATH)/%.cpp,$(OBJ_PATH)/%.o,$(SRC))
OBJ := $(patsubst %.cpp,$(OBJ_PATH)/%.o,$(OBJ))

HEADERS = $(wildcard $(INC_PATH)/*.hpp)

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -gdwarf-2 -g -I$(INC_PATH)

all: normal_build

print: print_build

test: test_build

normal_build: 
	@if [ -f $(OBJ_PATH)/.print_mode ]; then \
		echo "Switching from print mode to normal mode"; \
		rm -rf $(OBJ_PATH); \
		mkdir -p $(OBJ_PATH); \
		touch $(OBJ_PATH)/.normal_mode; \
		$(MAKE) --no-print-directory $(NAME); \
	elif [ -f $(OBJ_PATH)/.test_mode ]; then \
		echo "Switching from test mode to normal mode"; \
		rm -rf $(OBJ_PATH); \
		mkdir -p $(OBJ_PATH); \
		touch $(OBJ_PATH)/.normal_mode; \
		$(MAKE) --no-print-directory $(NAME); \
	elif [ ! -f $(OBJ_PATH)/.normal_mode ]; then \
		echo "First build in normal mode"; \
		mkdir -p $(OBJ_PATH); \
		touch $(OBJ_PATH)/.normal_mode; \
		$(MAKE) --no-print-directory $(NAME); \
	else \
		$(MAKE) --no-print-directory $(NAME); \
	fi

print_build:
	@if [ -f $(OBJ_PATH)/.normal_mode ]; then \
		echo "Switching from normal mode to print mode"; \
		rm -rf $(OBJ_PATH); \
		mkdir -p $(OBJ_PATH); \
		touch $(OBJ_PATH)/.print_mode; \
		$(MAKE) --no-print-directory $(NAME); \
	elif [ -f $(OBJ_PATH)/.test_mode ]; then \
		echo "Switching from test mode to print mode"; \
		rm -rf $(OBJ_PATH); \
		mkdir -p $(OBJ_PATH); \
		touch $(OBJ_PATH)/.print_mode; \
		$(MAKE) --no-print-directory $(NAME); \
	elif [ ! -f $(OBJ_PATH)/.print_mode ]; then \
		echo "First build in print mode"; \
		mkdir -p $(OBJ_PATH); \
		touch $(OBJ_PATH)/.print_mode; \
		$(MAKE) --no-print-directory $(NAME); \
	else \
		$(MAKE) --no-print-directory $(NAME); \
	fi

test_build:
	@if [ -f $(OBJ_PATH)/.normal_mode ]; then \
		echo "Switching from normal mode to test mode"; \
		rm -rf $(OBJ_PATH); \
		mkdir -p $(OBJ_PATH); \
		touch $(OBJ_PATH)/.test_mode; \
		$(MAKE) --no-print-directory $(NAME); \
	elif [ -f $(OBJ_PATH)/.print_mode ]; then \
		echo "Switching from print mode to test mode"; \
		rm -rf $(OBJ_PATH); \
		mkdir -p $(OBJ_PATH); \
		touch $(OBJ_PATH)/.test_mode; \
		$(MAKE) --no-print-directory $(NAME); \
	elif [ ! -f $(OBJ_PATH)/.test_mode ]; then \
		echo "First build in test mode"; \
		mkdir -p $(OBJ_PATH); \
		touch $(OBJ_PATH)/.test_mode; \
		$(MAKE) --no-print-directory $(NAME); \
	else \
		$(MAKE) --no-print-directory $(NAME); \
	fi

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(if $(wildcard $(OBJ_PATH)/.print_mode), \
		$(CC) $(CFLAGS) -DPRINT=1 -c $< -o $@, \
			$(if $(wildcard $(OBJ_PATH)/.test_mode), \
				$(CC) $(CFLAGS) -DTEST=1 -c $< -o $@, \
				$(CC) $(CFLAGS) -c $< -o $@ \
			) \
	)

$(OBJ_PATH)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(if $(wildcard $(OBJ_PATH)/.print_mode), \
		$(CC) $(CFLAGS) -DPRINT=1 -c $< -o $@, \
			$(if $(wildcard $(OBJ_PATH)/.test_mode), \
				$(CC) $(CFLAGS) -DTEST=1 -c $< -o $@, \
				$(CC) $(CFLAGS) -c $< -o $@ \
			) \
	)

$(NAME): ${OBJ} Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@if [ -f $(OBJ_PATH)/.print_mode ]; then \
		echo "Compiled with debug prints enabled"; \
	elif [ -f $(OBJ_PATH)/.test_mode ]; then \
		echo "Compiled with tests enabled"; \
	else \
		echo "Compiled in normal mode"; \
	fi

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re print test normal_build print_build test_build