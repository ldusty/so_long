NAME 	=	so_long

CFILES	=	src/if_map_ok.c src/if_map_valid.c src/inits.c src/mlx_game.c\
			src/mlx_game_utils.c src/mlx_game_utils2.c src/so_long.c

OBJECTS	= $(CFILES:.c=.o)

D_FILES =	$(patsubst %.c,%.d,$(CFILES))

LIB_PATH = libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX		=	-L mlx -lmlx -framework OpenGL -framework AppKit

.PHONY	:	all clean fclean re

all		: lib $(NAME)

lib		:
	make -C $(LIB_PATH) all

$(NAME)	:	$(OBJECTS) $(LIB_PATH)libft.a
	make -C ./mlx
	$(CC) $(CFLAGS)  $(OBJECTS) $(LIB_PATH)libft.a $(MLX) -o $(NAME)

%.o 	:	%.c	$(LIB_PATH)libft.a
	$(CC) $(CFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean	:
	make -C $(LIB_PATH) clean
	rm -f $(OBJECTS) $(D_FILES)

fclean	:	clean
	make -C $(LIB_PATH) fclean
	make clean -C ./mlx
	rm -f $(NAME)

re		:	fclean all