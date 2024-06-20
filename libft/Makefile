# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 14:19:38 by smoroz            #+#    #+#              #
#    Updated: 2024/06/06 14:07:32 by smoroz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCS = libft.h
LIBC = ar -rcs

SRCS = ft_strlen.c ft_isspace.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c
#		ft_isascii.c \
#		ft_isprint.c ft_tolower.c ft_toupper.c \
#		ft_strchr.c ft_strrchr.c \
#		ft_strncmp.c ft_memset.c ft_bzero.c \
#		ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
#		ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c \
#		ft_strdup.c ft_calloc.c \
#		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
#		ft_itoa.c ft_strmapi.c ft_striteri.c \
#		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
#		get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS) $(INCS)
		$(LIBC) $(NAME) $(OBJS)

%.o: %.c $(INCS)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS) $(INCS)
		$(LIBC) $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus