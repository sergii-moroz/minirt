/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:50:44 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 15:55:36 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	set_light(char *line, t_light *l)
{
	float	tmp_f;
	int		i;

	i = 0;
	triple_float_handler(line, &l->pivot, &i);
	i = get_next_digit(line, i);
	tmp_f = ft_atof(line + i, &i);
	l->intencity = (double)tmp_f;
	i = get_next_digit(line, i);
	triple_int_handler(line, &l->color, &i);
}

void	set_camera(char *line, t_camera *c)
{
	float	tmp_f;
	int		i;

	i = 0;
	triple_float_handler(line, &c->pivot, &i);
	i = get_next_digit(line, i);
	triple_float_handler(line, &c->w, &i);
	i = get_next_digit(line, i);
	tmp_f = ft_atof(line + i, &i);
	c->hfov = (double)tmp_f;
}

void	set_ambient(char *line, t_ambient *a)
{
	float	tmp_f;
	int		i;

	i = 0;
	tmp_f = ft_atof(line + i, &i);
	a->intencity = (double)tmp_f;
	i = get_next_digit(line, i);
	triple_int_handler(line, &a->color, &i);
}
