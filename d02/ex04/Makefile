# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsergien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 08:37:37 by tsergien          #+#    #+#              #
#    Updated: 2018/10/03 08:38:23 by tsergien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

SRC_FILES = main.cpp Fixed.class.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)

HEADER = -I Fixed.class.hpp

WWW = -Wall -Wextra -Werror

COLOR = \x1b[38;5;218m

RESET_COLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@clang++ $(OBJ_FILES) $(HEADER)  -o $(NAME)  
		@echo "$(COLOR)***		$(NAME) compiled		***$(RESET_COLOR)"

%.o: %.cpp
		@clang++ $(WWW) -c $< -o $@
		@echo "$(COLOR)***		obj files compiled		***$(RESET_COLOR)"

clean:
		@rm -f $(OBJ_FILES)
		@echo "$(COLOR)***		obj files deleted		***$(RESET_COLOR)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(COLOR)***		$(NAME) deleteed		***$(RESET_COLOR)"

re: fclean all
