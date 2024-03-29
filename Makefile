CC = cc -g3

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC = main.c \
	utils/ft_error.c utils/map_utils.c utils/check_ber_file.c utils/loading.c \
	parse/check_map_items.c parse/check_map.c parse/parse.c parse/flood_map.c \
	init/init_data.c init/init_data_utils.c \
	display/display_map.c display/display_utils.c \
	moves/data_moves.c moves/move_perso.c moves/move_perso_utils.c
	
HEADER = so_long.h

LIBFT = libft/libft.a

Mlx = minilibx-linux

MiniLibX_exec = minilibx-linux/libmlx.a

OBJ = $(SRC:.c=.o)

# Define ANSI color codes
GREEN = \033[0;32m
BLUE = \033[0;34m
CYAN = \033[0;36m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
NC = \033[0m # No Color

all: $(Mlx) $(NAME)

$(NAME): $(OBJ) $(HEADER) $(LIBFT) $(MiniLibX_exec)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MiniLibX_exec) -lXext -lX11 -lm
	@echo "$(GREEN)			*----------------------------------*\n \
				|        [OK] $(NAME) created      |\n \
				*----------------------------------*$(NC)"

.c.o: 
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft
	@echo "$(BLUE)			*----------------------------------*\n \
				|        [OK] LIBFT created        |\n \
				*----------------------------------*$(NC)"

# minilibx-linux:
# 	@git clone https://github.com/42Paris/minilibx-linux.git $@

$(Mlx):
	@git clone https://github.com/42Paris/minilibx-linux.git $@
	@make -C $@
	@echo "$(CYAN)			*----------------------------------*\n \
				|        [OK] MiniLibX created     |\n \
				*----------------------------------*$(NC)"	

clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@make clean -C minilibx-linux
	@echo "$(YELLOW)[OK] so_long clean completed$(NC)"

fclean: clean
	@rm -f $(NAME)
	@rm -rf minilibx-linux
	@make fclean -C libft
	@echo "$(PURPLE)[OK] so_long fclean completed$(NC)"

re: fclean all

.PHONY: all clean fclean re