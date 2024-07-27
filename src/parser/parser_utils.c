/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:58:00 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 18:02:09 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static int	get_next_char_after_comma(char *line, int i)
{
	while (line[i] != ',')
		i++;
	return (i + 1);
}

void	*ft_malloc(size_t size, t_scene *sc)
{
	void	*p;

	p = malloc(size);
	if (!p)
	{
		perror(RED"ERROR: memory allocation."RESET);
		sc->had_error = 1;
	}
	return (p);
}

int	get_next_digit(char *line, int i)
{
	while (!ft_isdigit(line[i]))
		i++;
	return (i);
}

void	triple_int_handler(char *line, t_color3 *color, int *i)
{
	int	tmp_i;

	tmp_i = (int)ft_atoi(line + *i);
	color->x = (double)(tmp_i) / (double)255;
	*i = get_next_char_after_comma(line, *i);
	tmp_i = ft_atoi(line + *i);
	color->y = (double)(tmp_i) / (double)255;
	*i = get_next_char_after_comma(line, *i);
	tmp_i = ft_atoi(line + *i);
	color->z = (double)(tmp_i) / (double)255;
}

void	triple_float_handler(char *line, t_vec3 *vec, int *i)
{
	float	tmp_f;

	tmp_f = ft_atof(line + *i, i);
	vec->x = (double)tmp_f;
	*i = get_next_char_after_comma(line, *i);
	tmp_f = ft_atof(line + *i, i);
	vec->y = (double)tmp_f;
	*i = get_next_char_after_comma(line, *i);
	tmp_f = ft_atof(line + *i, i);
	vec->z = (double)tmp_f;
}
