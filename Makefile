NAME		= cub3D

MLX			=	libmlx.a
OBJS_DIR	=	./objs
SRCS_DIR	=	./srcs
MLX_DIR 	=	./mlx_linux
HEADERS		=	./include/cub3d.h
LIBS		=	-lmlx -lX11 -lXext -lbsd -lm
INC_DIR 	=	./include
LINK		=	-I$(INC_DIR)
SRC_FILES	=	cub3d.c \
				player.c \
				drawing2.c \
				drawing.c \
				screenshot.c \
				get_next_line_utils.c \
				scan_map.c \
				init_func.c \
				sprites.c \
				sprite_util.c \
				error_out.c \
				map_check.c \
				set_textures.c \
				utils1.c \
				ft_parsing.c \
				settings.c \
				moving_keys.c \
				get_next_line.c \
				ft_list_utils.c \
				check_what.c \

SRCS 		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS 		= $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o, $(SRCS))
DEPS 		= $(OBJS:.o=.d)

CFLAGS	= -Wall -Wextra -Werror -MMD -MP
RM		= rm -rf
CC		= gcc

all:		$(NAME)

-include $(DEPS)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS) | $(OBJS_DIR)
	${CC} $(CFLAGS) $(LINK) -I $(MLX_DIR) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

${NAME}: 	${OBJS}
	@make -C mlx_linux -f Makefile
	${CC} -o ${NAME} ${OBJS} ${LIBS}

clean:
				$(MAKE) -C mlx_linux clean
				$(RM) $(OBJS) $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re