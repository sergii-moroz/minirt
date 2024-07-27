/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:30:36 by smoroz            #+#    #+#             */
/*   Updated: 2023/10/19 15:08:15 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_256(int n)
{
	if (n < 0)
		n += 256;
	return (n);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (0);
	while (*s1 == *s2 && count < n && *s1)
	{
		count++;
		if (count < n)
		{
			s1++;
			s2++;
		}
	}
	return (ft_256(*s1) - ft_256(*s2));
}
