NAME		=	cub3D
CC			=	gcc
CFLAGS		=	-g3 -Wall -Werror -Wextra
RM			=	rm -rf

#LIBS
LIBFT		=	libs/libft/libft.a

#SRC
ERROR		=	put_error.c
ARGUMENT	=	check_argument.c get_map.c check_map.c
FREE		=	free_str.c
MAIN		=	main.c

#OBJS
ERROR_DIR	=	$(addprefix error/, $(ERROR))
ARG_DIR		=	$(addprefix map/, $(ARGUMENT))
SRC_DIR		=	$(addprefix src/, $(ERROR_DIR) $(ARG_DIR) $(MAIN))

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

fclean: clean
	@$(RM) $(NAME)
	@echo "Eliminado " $(NAME)

re: fclean all

.PHONY:	all clean fclean re