NAME = sed_for_losers

CC = c++

CFLAGS = -std=c++98 -Wall -Werror -Wextra -fsanitize=address

SRC = main2.cpp

#HEADER = 

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Makefile 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
