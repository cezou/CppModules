NAME = cpp04

OBJ_PATH = .objs
SRC_PATH = srcs
INC_PATH = includes

# Mode tracking files
MODE_NORMAL = .normal_mode
MODE_DEBUG = .debug_mode

SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
SRC := $(addprefix $(SRC_PATH)/,$(filter-out main.cpp,$(SRC)))
SRC += main.cpp

OBJ = $(patsubst $(SRC_PATH)/%.cpp,$(OBJ_PATH)/%.o,$(filter $(SRC_PATH)/%,$(SRC)))
OBJ += $(patsubst %.cpp,$(OBJ_PATH)/%.o,$(filter-out $(SRC_PATH)/%,$(SRC)))

HEADERS = AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp IMateriaSource.hpp Ice.hpp MateriaSource.hpp Utils.hpp
HEADERS := $(addprefix $(INC_PATH)/,$(HEADERS))

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g -I$(INC_PATH) -gdwarf-2


all: normal

normal: $(MODE_NORMAL) $(NAME)

debug: $(MODE_DEBUG) $(NAME)

# Create normal mode tracker and force relink if switching from debug
$(MODE_NORMAL):
	@if [ -f $(MODE_DEBUG) ]; then \
		$(MAKE) fclean; \
		echo "Switching from debug to normal mode - forcing relink"; \
		rm -f $(NAME) $(MODE_DEBUG); \
	fi
	@touch $(MODE_NORMAL)

# Create debug mode tracker and force relink if switching from normal
$(MODE_DEBUG):
	@if [ -f $(MODE_NORMAL) ]; then \
		$(MAKE) fclean; \
		echo "Switching from normal to debug mode - forcing relink"; \
		rm -f $(NAME) $(MODE_NORMAL); \
	fi
	@touch $(MODE_DEBUG)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DEBUG_CFLAGS) -c $< -o $@

$(OBJ_PATH)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DEBUG_CFLAGS) -c $< -o $@

# Set DEBUG_CFLAGS based on mode for object compilation
$(NAME): $(OBJ) $(HEADERS) Makefile
	@if [ -f $(MODE_DEBUG) ]; then \
		echo "Building in debug mode (PRINT=1)"; \
		$(MAKE) DEBUG_CFLAGS="-D PRINT=1" link; \
	else \
		echo "Building in normal mode (PRINT=0)"; \
		$(MAKE) DEBUG_CFLAGS="-D PRINT=0" link; \
	fi

# Set DEBUG_CFLAGS based on mode for object compilation
ifeq ($(wildcard $(MODE_DEBUG)),$(MODE_DEBUG))
    DEBUG_CFLAGS = -D PRINT=0
else ifeq ($(wildcard $(MODE_NORMAL)),$(MODE_NORMAL))
    DEBUG_CFLAGS = -D PRINT=1
else
    DEBUG_CFLAGS = -D PRINT=0
endif


link:
	$(CC) $(CFLAGS) $(DEBUG_CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME) $(MODE_NORMAL) $(MODE_DEBUG)

re: fclean all

.PHONY: all normal debug clean fclean re link
