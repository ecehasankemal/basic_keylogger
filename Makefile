# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 16:14:28 by hece              #+#    #+#              #
#    Updated: 2023/04/25 16:18:40 by hece             ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME = keylogger
FLAG = -Wall -Wextra -Werror
SRC = $(shell find . -name "*.c")
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAG) -o $@ $^
	@echo "\n\033[92m $@ built ✅\033[0m\n"

%.o: %.c
	@gcc $(FLAG) -c $<
	@echo "\033[36m $< compiled ✅\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\n\033[36m object files removed 👋\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@echo "\n\033[36m executable removed 👋\033[0m\n"

re: fclean all

.PHONY: all clean fclean re
