NAME = PmergeMe 

CC = c++

CFLAGS = -std=c++98 -pedantic -Wall -Werror -Wextra -fsanitize=address

SRC = main.cpp PmergeMe.cpp 

HEADERS = PmergeMe.hpp 

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Makefile $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

