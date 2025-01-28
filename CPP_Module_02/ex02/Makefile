NAME = raw

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

SRC = main.cpp \
	  Fixed.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all