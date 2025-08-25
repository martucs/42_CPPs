NAME = PmergeMe 

DEBUG_NAME = PmergeMe_debug

CC = c++

CFLAGS = -std=c++98 -pedantic -Wall -Werror -Wextra -fsanitize=address

DEBUG_FLAGS := -DDEBUG_MODE -g

SRC = main.cpp PmergeMe.cpp 

HEADERS = PmergeMe.hpp 

OBJ = $(SRC:.cpp=.o)

OBJ_DEBUG = $(SRC:.cpp=_debug.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Makefile $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(DEBUG_NAME)

# Link debug executable
$(DEBUG_NAME): $(OBJ_DEBUG)
	$(CC) $(CFLAGS) $(OBJ_DEBUG) -o $(DEBUG_NAME)

main_debug.o: main.cpp Makefile $(HEADERS)
	$(CC) $(CFLAGS) -c main.cpp -o main_debug.o

PmergeMe_debug.o: PmergeMe.cpp Makefile $(HEADERS)
	$(CC) $(CFLAGS) -c PmergeMe.cpp -o PmergeMe_debug.o

clean:
	rm -rf $(OBJ) $(OBJ_DEBUG)

fclean: clean
	rm -rf $(NAME) $(DEBUG_NAME)

re: fclean all

.PHONY: all clean fclean re

