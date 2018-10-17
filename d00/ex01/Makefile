# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsergien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 12:47:04 by tsergien          #+#    #+#              #
#    Updated: 2018/10/01 12:47:06 by tsergien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = deathnote

SRC_FILES = main.cpp Person.cpp Notebook.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)

HEADER = -I Person.hpp -I Notebook.hpp

WWW = -Wall -Wextra -Werror

COLOR = \x1b[38;5;218m

RESET_COLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@clang++ $(OBJ_FILES) $(HEADER) -o $(NAME) 
		@echo "$(COLOR)***		$(NAME) compiled		***$(RESET_COLOR)"

%.o: %.cpp $(HEADER)
		@clang++ $(WWW) -c $< -o $@

clean:
		@rm -f $(OBJ_FILES)
		@echo "$(COLOR)***		obj files deleted		***$(RESET_COLOR)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(COLOR)***		$(NAME) deleteed		***$(RESET_COLOR)"

re: fclean all
