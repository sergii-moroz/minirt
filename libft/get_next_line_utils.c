/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:46:30 by smoroz            #+#    #+#             */
/*   Updated: 2023/12/05 16:08:14 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchridx(const char *s, int c)
{
	int	i;
	int	len;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if (*(s + i) == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*next_line_from_buff(char *s_buff)
{
	char	*next_line;
	int		size;

	if (!s_buff)
		return (NULL);
	if (ft_strlen(s_buff) == 0)
	{
		return (NULL);
	}
	next_line = NULL;
	size = ft_strchridx(s_buff, '\n');
	if (size < 0)
	{
		size = ft_strlen(s_buff) - 1;
	}
	next_line = malloc((size + 1 + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	ft_memcpy(next_line, s_buff, size + 1);
	next_line[size + 1] = '\0';
	return (next_line);
}

char	*cleanup_s_buff(char *s_buff)
{
	int		slen;
	int		n_idx;
	char	*stemp;

	if (!s_buff)
		return (NULL);
	slen = ft_strlen(s_buff);
	if (slen == 0)
		return (free(s_buff), NULL);
	n_idx = ft_strchridx(s_buff, '\n');
	if (n_idx < 0 || slen == (n_idx + 1))
		return (free(s_buff), NULL);
	slen -= (n_idx + 1);
	stemp = malloc((slen + 1) * sizeof(char));
	if (!stemp)
		return (NULL);
	ft_memcpy(stemp, s_buff + n_idx + 1, slen);
	stemp[slen] = '\0';
	free(s_buff);
	s_buff = stemp;
	return (s_buff);
}
