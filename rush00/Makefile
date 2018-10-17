
NAME = ft_retro

SRC_FILES = Starfighter.cpp Enemy.cpp Droid.cpp Character.cpp Squad.cpp main.cpp Background.cpp

SRC_DIR = src/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES = $(SRC_FILES:.cpp=.o)

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

HEADER = -I includes

WWW = -Wall -Wextra -Werror -g

COLOR = \x1b[38;5;218m

RESET_COLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
		@clang++ $(OBJ) -o $(NAME) $(HEADER) -lncurses
		@echo "$(COLOR)***		$(NAME) compiled		***$(RESET_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
		@mkdir -p $(OBJ_DIR)
		@clang++ $(WWW) -o $@ -c $< $(HEADER)
		@echo "$(COLOR)***		obj files compiled		***$(RESET_COLOR)"

clean:
		@rm -rf $(OBJ_DIR)
		@echo "$(COLOR)***		obj files deleted		***$(RESET_COLOR)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(COLOR)***		$(NAME) deleteed		***$(RESET_COLOR)"

re: fclean all


