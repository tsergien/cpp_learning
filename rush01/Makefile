NAME = ft_gkrellm
CLANG = clang++ -Wall -Werror -Wextra -g
SRC = main.cpp TextMode.cpp HostnameModule.cpp OsInfoModule.cpp\
	 DateTimeModule.cpp CPUModule.cpp RAMModule.cpp NetworkModule.cpp\
	 DiskModule.cpp GraphicalMode.cpp
OBJ = $(SRC:.cpp=.o)
COLOR = \x1b[38;5;117m
RESET_COLOR = \033[0m


INCLUDES    =   -I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-F./frameworks

FRAMEWORKS  =   -F./frameworks \
				-rpath ./frameworks \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \


all: $(NAME)

$(NAME): $(OBJ)
	@$(CLANG) -o $(NAME) $(OBJ) $(FRAMEWORKS) $(INCLUDES) -lncurses
	@echo "$(COLOR)***		$(NAME) compiled		***$(RESET_COLOR)"

%.o: %.cpp
	@$(CLANG) -o $@ -c $< $(INCLUDES)

clean:
	@rm -rf $(OBJ)
	@echo "$(COLOR)***		obj files deleted		***$(RESET_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR)***		$(NAME) deleted		***$(RESET_COLOR)"

re: fclean all
