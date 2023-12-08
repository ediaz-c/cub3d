NAME		=	cub3D
CC			=	gcc
CFLAGS		=	-MMD -Wall -Werror -Wextra
RM			=	rm -rf

#LIBS
LIBFT_PATH	=	libs/libft
MLX_PATH	=	libs/mlx
LIBFT		=	-L$(LIBFT_PATH) -lft
MLX			=	-L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

#SRC
ERROR		=	put_error.c
MAIN		=	main.c
ARGUMENT	=	check_argument.c get_cub.c check_map.c map_utils.c
FREE		=	free_str.c free_cube.c
GAME		=	game.c textures.c close.c loop.c handler_key.c player.c move.c rotate.c handler_mouse.c
MINI		=	minimap.c player_minimap.c
RAYCAST		=	raycast.c raycasting_draw_line.c raycasting_operations_wall.c raycasting_operations_floor_ceiling.c
UTILS		=	create_cube.c check_map_utils.c check_row.c get_cub_utils.c pos.c

#OBJS
ERROR_DIR	=	$(addprefix error/, $(ERROR))
ARG_DIR		=	$(addprefix cub/, $(ARGUMENT))
FREE_DIR	=	$(addprefix free/, $(FREE))
UTILS_DIR	=	$(addprefix utils/, $(UTILS))
GAME_DIR	=	$(addprefix game/, $(GAME))
MINI_DIR	=	$(addprefix minimap/, $(MINI))
RAY_DIR		=	$(addprefix raycast/, $(RAYCAST))
SRC_DIR		=	$(addprefix src/, $(ERROR_DIR) $(ARG_DIR) $(FREE_DIR) $(UTILS_DIR) $(MAIN) $(GAME_DIR) $(MINI_DIR) $(RAY_DIR))

OBJS		=	$(SRC_DIR:.c=.o)
DEPS		=	$(OBJS:.o=.d)

# COLORS
OFF			=	\033[0m
GREEN		=	\033[1;92m
RED			=	\033[1;91m
PURPLE		=	\033[1;95m
WHITE		=	\033[1;97m

BLINK		=	\033[5m

all:	$(NAME)


.c.o:	%.o:%.c
	@${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	# @clear
	@echo "$(GREEN)$(BLINK)	Compiling...$(OFF)"
	@make -C $(MLX_PATH)
	@echo "$(PURPLE) MLX		$(GREEN)Compilado$(OFF)"
	@make -C $(LIBFT_PATH)
	@echo "$(PURPLE) LIBFT		$(GREEN)Compilado$(OFF)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX)
	@echo "$(PURPLE) $(NAME)		$(GREEN)Compilado$(OFF)"
	@echo "\n"
	@echo	"$(PURPLE)$(BLINK)  ██████╗██╗   ██╗██████╗ ██████╗ ██████╗\n" \
			"██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗\n"\
			"██║     ██║   ██║██████╔╝ █████╔╝██║  ██║\n"\
			"██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║\n"\
			"╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝\n"\
			" ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝\n$(OFF)"\

debug:	CFLAGS += -g3 -fsanitize=address
debug:	all

clean:
	@echo "$(WHITE)$(BLINK)$(RED)Cleaning...$(OFF)"
	@$(RM) $(OBJS)
	@echo "$(PURPLE) $(NAME)		$(RED)Deleted objects$(OFF)"
	@make clean -C libs/libft
	@echo "$(PURPLE) Libft		$(RED)Deleted objects$(OFF)"
	@make clean -C libs/mlx
	@echo "$(PURPLE) Mlx		$(RED)Deleted objects$(OFF)"
	@echo "$(PURPLE) Dependencies	$(RED)Deleted$(OFF)"
	@$(RM) $(DEPS)

fclean: clean
	@echo "\n$(WHITE)$(BLINK)$(RED)Cleaning libs and binary...$(OFF)"
	@echo "$(PURPLE) $(NAME)		$(RED)Deleted$(OFF)"
	@$(RM) $(NAME)
	@echo "$(PURPLE) Libft		$(RED)Deleted$(OFF)"
	@make fclean -C libs/libft
	@echo "$(PURPLE) Mlx		$(RED)Deleted$(OFF)"
	@make clean -C libs/mlx

re: fclean all

.PHONY:	all clean fclean re