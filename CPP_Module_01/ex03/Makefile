NAME = z

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
	  HumanA.cpp \
	  HumanB.cpp \
	  Weapon.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all