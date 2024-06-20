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

SRC_DIRS	=	src src/app src/hilbert_curve src/common
vpath			%.c $(SRC_DIRS)

SRCS			=	main.c app.c hooks.c update.c hilbert_curve.c \
					color.c error.c \
					utils_check_input.c

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
#			cd ./

re:			fclean all

run:		all
			./miniRT aaa

crun:		clean run

info:
	git diff --numstat | awk '{added += $$1; deleted += $$2} END {print added - deleted}'

.PHONY: all clean fclean re run frun