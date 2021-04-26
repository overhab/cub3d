NAME	= cub3D

MLX			=	libmlx.a
OBJ_DIR		=	./object
OBJS		=	$(SRCS:.c=.o)
SRC_DIR		=	./srcs
MLX_DIR 	=	./mlx_linux
HEADER		=	./include/cub3d.h
LIBS		=	-lmlx -lX11 -lXext -lbsd -lm
INC_DIR 	=	./include
LINK		=	-I$(INC_DIR)
SRCS		=	./srcs/cub3d.c \
				./srcs/player.c \
				./srcs/drawing2.c \
				./srcs/drawing.c \
				./srcs/screenshot.c \
				./srcs/get_next_line_utils.c \
				./srcs/scan_map.c \
				./srcs/init_func.c \
				./srcs/sprites.c \
				./srcs/sprite_util.c \
				./srcs/error_out.c \
				./srcs/map_check.c \
				./srcs/set_textures.c \
				./srcs/utils1.c \
				./srcs/ft_parsing.c \
				./srcs/settings.c \
				./srcs/moving_keys.c \
				./srcs/get_next_line.c \
				./srcs/ft_list_utils.c \
				./srcs/check_what.c \

CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
CC		= gcc

all:		$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	${CC} $(CFLAGS) $(LINK) -I $(MLX_DIR) -c $< -o $@

${NAME}: 	${OBJS}
	@make -C mlx_linux -f Makefile
	${CC} -o ${NAME} ${OBJS} ${LIBS}

clean:
				$(MAKE) -C mlx_linux clean
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re