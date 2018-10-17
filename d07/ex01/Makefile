
NAME = me

SRC_FILES = iter.cpp 

OBJ_FILES = $(SRC_FILES:.cpp=.o)

HEADER = -I

WWW = -Wall -Wextra -Werror

COLOR = \x1b[38;5;218m

RESET_COLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@clang++ $(OBJ_FILES) -o $(NAME)
		@echo "$(COLOR)***		$(NAME) compiled		***$(RESET_COLOR)"

%.o: %.cpp
		@clang++ $(WWW) -o $@ -c $< 
		@echo "$(COLOR)***		obj files compiled		***$(RESET_COLOR)"

clean:
		@rm -f $(OBJ_FILES)
		@echo "$(COLOR)***		obj files deleted		***$(RESET_COLOR)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(COLOR)***		$(NAME) deleteed		***$(RESET_COLOR)"

re: fclean all


