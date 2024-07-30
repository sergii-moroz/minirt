/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:58:00 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/30 16:00:06 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	*ft_malloc(size_t size, t_scene *sc)
{
	void	*p;

	p = malloc(size);
	if (!p)
	{
		sc->had_error = 1;
		perror(RED"ERROR: memory allocation."RESET);
	}
	return (p);
}

void	parse_position(char *s, t_vec3 *pos, t_scene *scene)
{
	char	**groups;
	int		count;

	if (scene->had_error)
		return ;
	count = ft_count_words(s, ',');
	if (count != 3)
	{
		scene->had_error = 1;
		printf(RED"ERROR:\n"RESET);
		printf(RED"\t|| "YELLOW"line: \""RESET);
		printf(BLACK"%s"YELLOW"\"\n"RESET, s);
		printf(RED"\t||\n\t|| "CYAN"The position's definition should "RESET);
		printf(CYAN"have THREE components [x, y, z]\n"RESET);
		printf(RED"\t|| "CYAN"Only "RED"%d"CYAN" were found.\n"RESET, count);
		return ;
	}
	groups = ft_split(s, ',');
	parse_double(*groups, &pos->x, scene);
	parse_double(*(groups + 1), &pos->y, scene);
	parse_double(*(groups + 2), &pos->z, scene);
	ft_cleanup(groups);
}

void	parse_double(char *s, double *val, t_scene *scene)
{
	if (scene->had_error)
		return ;
	if (ft_isvalid_float(s))
		*val = ft_atof(s);
	else
		parser_error_float(s, scene);
}

void	parse_integer(char *s, double *val, t_scene *scene)
{
	int	rgb;

	if (scene->had_error)
		return ;
	if (ft_isvalid_int(s))
	{
		rgb = ft_atoi(s);
		if (rgb >= 0 && rgb <= 255)
			*val = (double)rgb / 255.0;
		else
		{
			scene->had_error = 1;
			printf(RED"ERROR:\n"RESET);
			printf(RED"\t|| "YELLOW"line: \""RESET);
			printf(BLACK"%s"YELLOW"\"\n"RESET, s);
			printf(RED"\t|| ");
			printf(CYAN"color value should be in range [0 - 255]\n"RESET);
		}
	}
	else
		parser_error_integer(s, scene);
}

void	parse_color(char *s, t_color3 *color, t_scene *scene)
{
	char	**groups;
	int		count;

	if (scene->had_error)
		return ;
	count = ft_count_words(s, ',');
	if (count != 3)
	{
		scene->had_error = 1;
		printf(RED"ERROR:\n"RESET);
		printf(RED"\t|| "YELLOW"line: \""RESET);
		printf(BLACK"%s"YELLOW"\"\n"RESET, s);
		printf(RED"\t||\n\t|| "CYAN"The color's definition should "RESET);
		printf(CYAN"have THREE components [r, g, b]\n"RESET);
		printf(RED"\t|| "CYAN"Only "RED"%d"CYAN" were found.\n"RESET, count);
		return ;
	}
	groups = ft_split(s, ',');
	parse_integer(*groups, &color->x, scene);
	parse_integer(*(groups + 1), &color->y, scene);
	parse_integer(*(groups + 2), &color->z, scene);
	ft_cleanup(groups);
}
