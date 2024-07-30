/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:20:24 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/30 15:56:02 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void	parse_fov(char *s, t_scene *scene)
{
	double	fov;

	if (scene->had_error)
		return ;
	if (ft_isvalid_float(s))
	{
		fov = ft_atof(s);
		if (fov >= 0.0 && fov <= 180.0)
			scene->camera.hfov = fov;
		else
		{
			scene->had_error = 1;
			printf(RED"ERROR:\n"RESET);
			printf(RED"\t|| "YELLOW"line : \""RESET);
			printf(BLACK"%s"YELLOW"\"\n"RESET, s);
			printf(RED"\t||\n\t|| "CYAN"The horizontal field of view "RESET);
			printf(CYAN"(fov) in degrees should be in range [0-180].\n"RESET);
		}
	}
	else
		parser_error_float(s, scene);
}

static void	set_camera(char *s, t_scene *scene)
{
	char	**groups;

	if (scene->had_error)
		return ;
	groups = ft_split_by_space(s);
	parse_position(*groups, &scene->camera.pivot, scene);
	parse_normals(*(groups + 1), &scene->camera.w, scene);
	parse_fov(*(groups + 2), scene);
	ft_cleanup(groups);
	if (!scene->had_error)
		scene->camera_count++;
}

static void	error_second_camera(char *s)
{
	printf(RED"ERROR:\n"RESET);
	printf(RED"\t|| "YELLOW"line: \""RESET);
	printf(BLACK"%s"YELLOW"\"\n"RESET, s);
	printf(RED"\t||\n\t|| "CYAN"*.rt file should contain "RESET);
	printf(CYAN"only one cameras's definition.\n"RESET);
	printf(RED"\t|| "CYAN"The second camera's was found.\n"RESET);
}

void	parse_camera(char *s, t_scene *scene)
{
	int	count;

	if (scene->had_error)
		return ;
	if (scene->camera_count)
	{
		scene->had_error = 1;
		error_second_camera(s);
		return ;
	}
	count = ft_count_words_by_space(s);
	if (count != 3)
	{
		scene->had_error = 1;
		printf(RED"ERROR:\n"RESET);
		printf(RED"\t|| "YELLOW"line: \""RESET);
		printf(BLACK"%.*s"YELLOW"\"\n"RESET, (int)ft_strlen(s) - 1, s);
		printf(RED"\t||\n\t|| "CYAN"The camera's definition should "RESET);
		printf(CYAN"have THREE groups of parameters.\n"RESET);
		printf(RED"\t|| "CYAN"{position} {orientation} {fov}\n"RESET);
		printf(RED"\t|| "CYAN"Only "RED"%d"CYAN" were found.\n"RESET, count);
		return ;
	}
	set_camera(s, scene);
}
