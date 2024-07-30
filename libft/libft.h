/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:19:15 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/29 15:15:54 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_ft_atof
{
	double	fract;
	double	div;
	int		sign;
	int		i;
	float	res;
}			t_ft_atof;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isspace(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
// int		ft_isascii(int c);
// int		ft_isprint(int c);
// int		ft_tolower(int c);
// int		ft_toupper(int c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
// char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);
// void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
// void	*ft_memmove(void *dst, const void *src, size_t len);
long	ft_atoi(const char *str);
double	ft_atof(char *s);
// int		ft_memcmp(const void *s1, const void *s2, size_t n);
// void	*ft_memchr(const void *s, int c, size_t n);
// void	*ft_calloc(size_t count, size_t size);
// char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strdup(const char *s1);
// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
int		ft_count_words(char const *s, char c);
char	**ft_cleanup(char **arr);
// char	*ft_itoa(int n);
// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// void	ft_striteri(char *s, void (*f)(unsigned int, char *));
// void	ft_putchar_fd(char c, int fd);
// void	ft_putstr_fd(char *s, int fd);
// void	ft_putendl_fd(char *s, int fd);
// void	ft_putnbr_fd(int n, int fd);
int	ft_isvalid_int(const char *str);
int	ft_isvalid_float(const char *str);

t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// GET NEXT LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*read_buff(int fd, char *s_buff);
char	*next_line_from_buff(char *s_buff);
char	*cleanup_s_buff(char *s_buff);
int		ft_strchridx(const char *s, int c);

//		atof
//void	ft_atof_init(t_ft_atof *atof);
//float	ft_atof(char *str, int *len);

#endif
