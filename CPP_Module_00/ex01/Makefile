# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manufern <manufern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 11:01:10 by manufern          #+#    #+#              #
#    Updated: 2025/07/02 14:52:59 by manufern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = PhoneBook

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRC = phone_book.cpp \
	  contact.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all