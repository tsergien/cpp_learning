# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsergien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 10:50:02 by tsergien          #+#    #+#              #
#    Updated: 2018/10/01 11:12:14 by tsergien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC_FILES = megaphone.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)

WWW = -Wall -Wextra -Werror

COLOR = \x1b[38;5;218m

RESET_COLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@clang++ $(OBJ_FILES) -o $(NAME)
		@echo "$(COLOR)***		$(NAME) compiled		***$(RESET_COLOR)"

%.o: %.cpp
		@clang++ $(WWW) -o $@ -c $<

clean:
		@rm -f $(OBJ_FILES)
		@echo "$(COLOR)***		obj files deleted		***$(RESET_COLOR)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(COLOR)***		$(NAME) deleteed		***$(RESET_COLOR)"

re: fclean all
