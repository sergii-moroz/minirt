NAME		=	miniRT

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -rf
MAKE		=	make

MLX_DIR		=	minilibx
MLX			=	mlx
MLX_LIB		=	./$(MLX_DIR)/lib$(MLX).a

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

LIBS			=	-L$(MLX_DIR) -l$(MLX) -framework OpenGL -framework AppKit \
				-L$(LIBFT_DIR) -lft

INC			=	-I includes

SRC_DIRS	=	src src/app src/common src/parser \
				src/vec3 src/ray src/geometry src/interval src/scene
vpath			%.c $(SRC_DIRS)

SRCS			=	main.c app.c hooks.c update.c \
					vec3.c vec3_utils1.c vec3_utils2.c vec3_utils3.c \
					vec3_random.c \
					camera.c camera_init.c camera_ray.c camera_shade.c \
					ray.c sphere.c interval.c \
					scene.c scene_print.c cylinder.c \
					plane.c plane_hit.c \
					color.c error.c random.c \
					parser.c validation.c \
					split_by_space.c parser_errors.c \
					parser_utils.c parser_utils2.c \
					parser_plane.c parser_sphere.c parser_cylinder.c \
					parser_camera.c parser_ambient.c parser_light.c

OBJS_DIR	=	obj
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all:		$(NAME)

$(MLX_LIB):
			@if [ ! -d $(MLX_DIR) ]; then \
				git clone https://github.com/pasqualerossi/minilibx.git $(MLX_DIR) && \
				$(MAKE) -C $(MLX_DIR); \
			fi

$(NAME):	$(MLX_LIB) $(LIBFT) $(OBJS_DIR) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

$(LIBFT):
			cd $(LIBFT_DIR) && $(MAKE) && $(MAKE) clean

$(OBJS_DIR):
			mkdir $@

$(OBJS_DIR)/%.o: %.c
			$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@ $(INC)

clean:
			cd $(LIBFT_DIR) && $(MAKE) clean
			$(RM) $(OBJS_DIR)

fclean:		clean
			cd $(LIBFT_DIR) && $(MAKE) fclean
			$(RM) $(NAME)
			$(RM) $(MLX_DIR)

re:			fclean all

run:		clean all
			./miniRT ./scene/scene.rt

test:		clean all
			./miniRT ./scene/test01.rt

info:
	git diff --numstat | awk '{added += $$1; deleted += $$2} END {print added - deleted}'

.PHONY: all clean fclean re run test
