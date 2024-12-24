NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o) 

FLAGS = -std=c++98 -Wall -Werror -Wextra -fsanitize=address

CC = c++

all: megaphone

megaphone: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean 
