NAME = ex01

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRC = main.cpp \



OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	