/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:49:51 by smoroz            #+#    #+#             */
/*   Updated: 2023/12/05 16:09:09 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_buff(int fd, char *s_buff)
{
	char	buff[BUFFER_SIZE + 1];
	int		count;
	char	*stemp;

	count = 1;
	while (!ft_strchr(s_buff, '\n') && count > 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
		{
			free(s_buff);
			return (NULL);
		}
		buff[count] = '\0';
		stemp = ft_strjoin(s_buff, buff);
		free(s_buff);
		s_buff = stemp;
	}
	return (s_buff);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*s_buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s_buff)
	{
		s_buff = malloc(sizeof(char));
		if (!s_buff)
			return (NULL);
		*s_buff = '\0';
	}
	if (!ft_strchr(s_buff, '\n'))
		s_buff = read_buff(fd, s_buff);
	next_line = next_line_from_buff(s_buff);
	s_buff = cleanup_s_buff(s_buff);
	return (next_line);
}
