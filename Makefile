BLUE = \033[0;94m
GREEN = \e[1;92m
RED = \033[0;91m
RESET = \033[1;30m
WHITE = \033[1;97m
YELLOW = \033[1;33m

EMOJI_PACKAGE = \360\237\223\246
EMOJI_HAMMER = \360\237\224\250
EMOJI_TRASH = \360\237\227\221\357\270\217

NAME = cub3d

CC = cc
CFLAGS = -Werror -Wextra -Wall

MINILIBX_PATH = minilibx-linux/
MINILIBX_NAME = libmlx.a
MINILIBX = $(MINILIBX_PATH)$(MINILIBX_NAME)

LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

INC = -I ./inc/
SRC_PATH = src/
OBJ_PATH = obj/

SRC = $(addprefix $(SRC_PATH), \
	main.c \
)

OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@printf "$(EMOJI_HAMMER)	$(BLUE)Compiling $(WHITE)$(NAME)		$(BLUE)%-33s$(WHITE)\r" $(notdir $@)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(MINILIBX):
	@make -sC $(MINILIBX_PATH)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) -lmlx
	@printf  "\n$(EMOJI_PACKAGE)	$(WHITE)$(NAME)$(RESET)			$(YELLOW)compiled$(WHITE)\n"

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(MINILIBX_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(MINILIBX)
	@printf "$(EMOJI_TRASH)	$(WHITE)$(NAME)$(RESET)		$(RED)removed$(WHITE)\n"

re: fclean all

.PHONY: all re clean fclean
