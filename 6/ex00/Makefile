NAME = convert

CC = g++

CFLAGS =  -std=c++98 -pedantic -g -Wall -Werror -Wextra 

SRC = main.cpp ScalarConverter.cpp 

HEADERS = ScalarConverter.hpp 

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

