NAME = phonebook

SRC = main.cpp Contact.cpp PhoneBook.cpp

HEADERS = PhoneBook.hpp Contact.hpp

OBJ = $(SRC:.cpp=.o) 

FLAGS = -std=c++98 -Wall -Werror -Wextra -fsanitize=address

CC = c++

all: phonebook

phonebook: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Makefile $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean 

