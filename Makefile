NAME		=	cub3D
CC			=	gcc
CFLAGS		=	-g3 #-Wall -Werror -Wextra
RM			=	rm -rf

#LIBS
LIBFT_PATH	=	libs/libft
MLX_PATH	=	libs/mlx
LIBFT		=	-L$(LIBFT_PATH) -lft
MLX			=	-L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

#SRC
ERROR		=	put_error.c
ARGUMENT	=	check_argument.c get_cub.c check_map.c
FREE		=	free_str.c free_cube.c
UTILS		=	create_cube.c check_map_utils.c check_row.c get_cub_utils.c
GAME		=	init.c dda.c textures.c ceiling_floor.c
MAIN		=	main.c

#OBJS
ERROR_DIR	=	$(addprefix error/, $(ERROR))
ARG_DIR		=	$(addprefix cub/, $(ARGUMENT))
FREE_DIR	=	$(addprefix free/, $(FREE))
UTILS_DIR	=	$(addprefix utils/, $(UTILS))
GAME_DIR	=	$(addprefix game/, $(GAME))
SRC_DIR		=	$(addprefix src/, $(ERROR_DIR) $(ARG_DIR) $(FREE_DIR) $(UTILS_DIR) $(MAIN) $(GAME_DIR))

OBJS		=	$(SRC_DIR:.c=.o)

all:	$(NAME)

.c.o:	%.o:%.c
	@${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	@make -C $(MLX_PATH)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX)

clean:
	@for obj in $(OBJS); do \
		$(RM) $$obj; \
		echo "Eliminado $$obj"; \
	done
	@make clean -C libs/libft
	@make clean -C libs/mlx

fclean: clean
	@$(RM) $(NAME)
	@echo "Eliminado " $(NAME)
	@make fclean -C libs/libft
	@make clean -C libs/mlx

re: fclean all

.PHONY:	all clean fclean re