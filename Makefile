NAME		=	cub3D
CC			=	gcc
CFLAGS		=	-g3 -Wall -Werror -Wextra
RM			=	rm -rf

#LIBS
LIBFT		=	libs/libft/libft.a

#SRC
ERROR		=	put_error.c
ARGUMENT	=	check_argument.c get_cub.c check_map.c
FREE		=	free_str.c free_cube.c
UTILS		=	create_cube.c check_map_utils.c check_row.c get_cub_utils.c
MAIN		=	main.c

#OBJS
ERROR_DIR	=	$(addprefix error/, $(ERROR))
ARG_DIR		=	$(addprefix cub/, $(ARGUMENT))
FREE_DIR	=	$(addprefix free/, $(FREE))
UTILS_DIR		=	$(addprefix utils/, $(UTILS))
SRC_DIR		=	$(addprefix src/, $(ERROR_DIR) $(ARG_DIR) $(FREE_DIR) $(UTILS_DIR) $(MAIN))

OBJS		=	$(SRC_DIR:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)	$(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)

$(LIBFT):
	@make -C libs/libft

clean:
	@for obj in $(OBJS); do \
		$(RM) $$obj; \
		echo "Eliminado $$obj"; \
	done
	@make clean -C libs/libft

fclean: clean
	@$(RM) $(NAME)
	@echo "Eliminado " $(NAME)
	@make fclean -C libs/libft

re: fclean all

.PHONY:	all clean fclean re