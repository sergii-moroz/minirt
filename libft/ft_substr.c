/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:04:33 by smoroz            #+#    #+#             */
/*   Updated: 2023/10/19 11:54:48 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	n;
	size_t	i;

	n = ft_strlen(s);
	if (n == 0 || len == 0 || (size_t)start >= n)
		return (ft_strdup(""));
	if ((size_t)start + len > n)
		len = n - start;
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(dst + i) = *(s + start + i);
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}
