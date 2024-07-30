/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:38:09 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/29 15:15:25 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_word_start(char const *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) && *(s + i) == c)
		i++;
	return (i);
}

static int	ft_find_word_end(char const *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

int	ft_count_words(char const *s, char c)
{
	int	count;
	int	len;
	int	i;
	int	size;

	len = ft_strlen(s);
	count = 0;
	i = 0;
	while (i < len)
	{
		i += ft_find_word_start(s + i, c);
		if (i < len)
		{
			count++;
			size = ft_find_word_end(s + i, c);
			i += size;
		}
	}
	return (count);
}

char	**ft_cleanup(char **arr)
{
	int	i;

	i = 0;
	while (*(arr + i))
	{
		free(*(arr + i));
		i++;
	}
	free(arr);
	arr = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	int		t[3];

	t[0] = ft_count_words(s, c);
	arr = malloc((t[0] + 1) * sizeof(char *));
	if (!arr)
		return (arr);
	i = 0;
	t[2] = 0;
	while (t[2] < t[0])
	{
		i += ft_find_word_start(s + i, c);
		if (i < ft_strlen(s))
		{
			t[1] = ft_find_word_end(s + i, c);
			*(arr + t[2]) = ft_substr(s, i, t[1]);
			if (!*(arr + t[2]))
				return (ft_cleanup(arr));
			i += t[1];
		}
		t[2]++;
	}
	*(arr + t[2]) = NULL;
	return (arr);
}
