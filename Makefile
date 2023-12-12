NAME		=	cub3D
CC			=	gcc
CFLAGS		=	-MMD -Wall -Werror -Wextra
RM			=	rm -rf

#LIBS
LIBFT_PATH	=	libs/libft
MLX_PATH	=	libs/mlx
LIBFT		=	-L$(LIBFT_PATH) -lft
MLX			=	-L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

## MANDATORY
# SRC MANDATORY
ERROR		=	put_error.c
MAIN		=	main.c
ARGUMENT	=	check_argument.c get_cub.c check_map.c map_utils.c
FREE		=	free_str.c free_cube.c
GAME		=	game.c textures.c close.c loop.c handler_key.c player.c move.c rotate.c
RAYCAST		=	raycast.c raycasting_draw_line.c raycasting_operations_wall.c raycasting_utils.c
UTILS		=	create_cube.c check_map_utils.c check_row.c get_cub_utils.c pos.c

# OBJS MANDATORY
ERROR_DIR	=	$(addprefix error/, $(ERROR))
ARG_DIR		=	$(addprefix cub/, $(ARGUMENT))
FREE_DIR	=	$(addprefix free/, $(FREE))
UTILS_DIR	=	$(addprefix utils/, $(UTILS))
GAME_DIR	=	$(addprefix game/, $(GAME))
RAY_DIR		=	$(addprefix raycast/, $(RAYCAST))
SRC_DIR		=	$(addprefix src/, $(ERROR_DIR) $(ARG_DIR) $(FREE_DIR) $(UTILS_DIR) $(MAIN) $(GAME_DIR) $(RAY_DIR))

OBJS		=	$(SRC_DIR:.c=.o)
DEPS		=	$(OBJS:.o=.d)

### BONUS
# SRC BONUS
CUB_BONUS	=	check_argument.c get_cub.c check_map.c map_utils.c
ERROR_BONUS	=	put_error.c
FREE_BONUS	=	free_str.c free_cube.c
GAME_BONUS	=	game.c textures.c close.c loop.c handler_key.c player.c move.c rotate.c handler_mouse.c
MINI_BONUS	=	minimap.c player_minimap.c
RAY_BONUS	=	raycast.c raycasting_draw_line.c raycasting_operations_wall.c raycasting_operations_floor_ceiling.c raycasting_utils.c
UTILS_BONUS	=	create_cube.c check_map_utils.c check_row.c get_cub_utils.c pos.c
MAIN_BONUS	=	main.c

# OBJS BONUS
CUB_BONUS_DIR	=	$(addprefix cub/, $(CUB_BONUS))
ERROR_BONUS_DIR	=	$(addprefix error/, $(ERROR_BONUS))
FREE_BONUS_DIR	=	$(addprefix free/, $(FREE_BONUS))
GAME_BONUS_DIR	=	$(addprefix game/, $(GAME_BONUS))
MINI_BONUS_DIR	=	$(addprefix minimap/, $(MINI_BONUS))
RAY_BONUS_DIR	=	$(addprefix raycast/, $(RAY_BONUS))
UTILS_BONUS_DIR	=	$(addprefix utils/, $(UTILS_BONUS))
SRC_BONUS_DIR	=	$(addprefix src_bonus/, $(ERROR_BONUS_DIR) $(CUB_BONUS_DIR) $(FREE_BONUS_DIR) $(UTILS_BONUS_DIR) $(MAIN_BONUS) $(GAME_BONUS_DIR) $(MINI_BONUS_DIR) $(RAY_BONUS_DIR))

OBJS_BONUS		=	$(SRC_BONUS_DIR:.c=.o)
DEPS_BONUS		=	$(OBJS_BONUS:.o=.d)

# COLORS
OFF			=	\033[0m
GREEN		=	\033[1;92m
RED			=	\033[1;91m
PURPLE		=	\033[1;95m
WHITE		=	\033[1;97m
YELLOW		=	\033[1;93m

BLINK		=	\033[5m

all:	$(NAME)


.c.o:	%.o:%.c
	@${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	@clear
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

bonus: $(OBJS_BONUS)
	@clear
	@echo "$(GREEN)$(BLINK)	Compiling...$(OFF)"
	@make -C $(MLX_PATH)
	@echo "$(PURPLE) MLX		$(GREEN)Compilado$(OFF)"
	@make -C $(LIBFT_PATH)
	@echo "$(PURPLE) LIBFT		$(GREEN)Compilado$(OFF)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME) $(LIBFT) $(MLX)
	@echo "$(PURPLE) $(NAME) $(YELLOW)bonus	$(GREEN)Compilado$(OFF)"
	@echo "\n"
	@echo "$(PURPLE)$(BLINK)  ██████╗██╗   ██╗██████╗ ██████╗ ██████╗     ██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗\n"\
							"██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗    ██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝\n"\
							"██║     ██║   ██║██████╔╝ █████╔╝██║  ██║    ██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗\n"\
							"██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║    ██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║\n"\
							"╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝    ██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║\n"\
							" ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝     ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝$(OFF)"

clean_bonus:
	@echo "$(WHITE)$(BLINK)$(RED)Cleaning...$(OFF)"
	@$(RM) $(OBJS_BONUS)
	@echo "$(PURPLE) $(NAME)		$(RED)Deleted objects$(OFF)"
	@make clean -C libs/libft
	@echo "$(PURPLE) Libft		$(RED)Deleted objects$(OFF)"
	@make clean -C libs/mlx
	@echo "$(PURPLE) Mlx		$(RED)Deleted objects$(OFF)"
	@echo "$(PURPLE) Dependencies	$(RED)Deleted$(OFF)"
	@$(RM) $(DEPS_BONUS)

fclean_bonus: clean_bonus
	@echo "\n$(WHITE)$(BLINK)$(RED)Cleaning libs and binary...$(OFF)"
	@echo "$(PURPLE) $(NAME)		$(RED)Deleted$(OFF)"
	@$(RM) $(NAME)
	@echo "$(PURPLE) Libft		$(RED)Deleted$(OFF)"
	@make fclean -C libs/libft
	@echo "$(PURPLE) Mlx		$(RED)Deleted$(OFF)"
	@make clean -C libs/mlx

.PHONY:	all clean fclean re