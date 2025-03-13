NAME = unnecessary_violence

CC = c++

CFLAGS = -std=c++98 -Wall -Werror -Wextra -fsanitize=address

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

HEADER = HumanA.hpp HumanB.hpp Weapon.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Makefile $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

