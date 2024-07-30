/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:05:55 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/30 16:00:19 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	parse_normals(char *s, t_vec3 *n, t_scene *scene)
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
		printf(RED"\t||\n\t|| "CYAN"The normal's definition should "RESET);
		printf(CYAN"have THREE components [Nx, Ny, Nz]\n"RESET);
		printf(RED"\t|| "CYAN"Only "RED"%d"CYAN" were found.\n"RESET, count);
		return ;
	}
	groups = ft_split(s, ',');
	parse_double(*groups, &n->x, scene);
	parse_double(*(groups + 1), &n->y, scene);
	parse_double(*(groups + 2), &n->z, scene);
	ft_cleanup(groups);
	check_normals(s, n, scene);
}

void	check_normals(char *s, t_vec3 *n, t_scene *scene)
{
	double	len;

	if (scene->had_error)
		return ;
	len = vec3_length(n);
	if (len < 0.999 || len > 1.001)
	{
		scene->had_error = 1;
		printf(RED"ERROR:\n"RESET);
		printf(RED"\t|| "YELLOW"line: \""RESET);
		printf(BLACK"%s"YELLOW"\"\n"RESET, s);
		printf(RED"\t||\n\t|| "CYAN"The normal's components should "RESET);
		printf(CYAN"be in range [-1.0, 1.0]\n"RESET);
		printf(RED"\t|| "CYAN"Normal's length should be equal 1.0\n"RESET);
		printf(RED"\t|| "CYAN"Normal's length: "RED"%f"CYAN".\n"RESET, len);
	}
}

void	parse_intencity(char *s, double *val, t_scene *scene)
{
	double	intencity;

	if (scene->had_error)
		return ;
	if (ft_isvalid_float(s))
	{
		intencity = ft_atof(s);
		if (intencity >= 0.0 && intencity <= 1.0)
			*val = intencity;
		else
		{
			scene->had_error = 1;
			printf(RED"ERROR:\n"RESET);
			printf(RED"\t|| "YELLOW"line : \""RESET);
			printf(BLACK"%s"YELLOW"\"\n"RESET, s);
			printf(RED"\t||\n\t|| "CYAN"The light intencity "RESET);
			printf(CYAN"should be in range [0.0 - 1.0].\n"RESET);
		}
	}
	else
		parser_error_float(s, scene);
}

void	parse_radius(char *s, double *val, t_scene *scene)
{
	double	radius;

	if (scene->had_error)
		return ;
	if (ft_isvalid_float(s))
	{
		radius = ft_atof(s);
		if (radius > 0.0)
			*val = radius / 2.0;
		else
		{
			scene->had_error = 1;
			printf(RED"ERROR:\n"RESET);
			printf(RED"\t|| "YELLOW"line : \""RESET);
			printf(BLACK"%s"YELLOW"\"\n"RESET, s);
			printf(RED"\t||\n\t|| "CYAN"Radius "RESET);
			printf(CYAN"should be greater then zero.\n"RESET);
		}
	}
	else
		parser_error_float(s, scene);
}

void	parse_height(char *s, double *val, t_scene *scene)
{
	double	height;

	if (scene->had_error)
		return ;
	if (ft_isvalid_float(s))
	{
		height = ft_atof(s);
		if (height > 0.0)
			*val = height;
		else
		{
			scene->had_error = 1;
			printf(RED"ERROR:\n"RESET);
			printf(RED"\t|| "YELLOW"line : \""RESET);
			printf(BLACK"%s"YELLOW"\"\n"RESET, s);
			printf(RED"\t||\n\t|| "CYAN"Height "RESET);
			printf(CYAN"should be greater then zero.\n"RESET);
		}
	}
	else
		parser_error_float(s, scene);
}
