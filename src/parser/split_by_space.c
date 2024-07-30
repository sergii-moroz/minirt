/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:11:47 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/30 16:00:40 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static int	ft_find_word_start(char const *s)
{
	int	i;

	i = 0;
	while (*(s + i) && ft_isspace(*(s + i)))
		i++;
	return (i);
}

static int	ft_find_word_end(char const *s)
{
	int	i;

	i = 0;
	while (*(s + i) && !ft_isspace(*(s + i)))
		i++;
	return (i);
}

int	ft_count_words_by_space(char const *s)
{
	int	i;
	int	len;
	int	count;

	len = ft_strlen(s);
	count = 0;
	i = 0;
	while (i < len)
	{
		i += ft_find_word_start(s + i);
		if (i < len)
		{
			count++;
			i += ft_find_word_end(s + i);
		}
	}
	return (count);
}

char	**ft_split_by_space(char const *s)
{
	char	**arr;
	size_t	i;
	int		t[3];

	t[0] = ft_count_words_by_space(s);
	arr = malloc((t[0] + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	t[2] = 0;
	while (t[2] < t[0])
	{
		i += ft_find_word_start(s + i);
		if (i < ft_strlen(s))
		{
			t[1] = ft_find_word_end(s + i);
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
