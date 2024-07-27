/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:59:01 by olanokhi          #+#    #+#             */
/*   Updated: 2024/07/25 12:55:49 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_atof_init(t_ft_atof *atof)
{
	atof->fract = 0;
	atof->div = 1;
	atof->sign = 1;
	atof->i = 0;
	atof->res = 0;
}

float	ft_atof(char *str, int *len)
{
	t_ft_atof		atof;

	ft_atof_init(&atof);
	while (ft_isspace(str[atof.i]))
		atof.i++;
	if (str[atof.i] == '-')
		atof.sign = -1;
	if (str[atof.i] == '+' || str[atof.i] == '-')
		atof.i++;
	while (ft_isdigit(str[atof.i]))
	{
		atof.res = atof.res * 10 + str[atof.i] - '0';
		atof.i++;
	}
	if (str[atof.i] == '.')
		atof.i++;
	while (ft_isdigit(str[atof.i]))
	{
		atof.fract = atof.fract * 10 + str[atof.i] - '0';
		atof.div *= 10;
		atof.i++;
	}
	atof.res = atof.res + atof.fract / atof.div;
	return (*len += atof.i, atof.res * atof.sign);
}
