/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:05:29 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/30 15:59:39 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void	set_plane(char *s, t_scene *scene)
{
	t_plane	*pl;
	t_geom	*geom;
	char	**groups;

	if (scene->had_error)
		return ;
	groups = ft_split_by_space(s);
	pl = ft_malloc(sizeof(t_plane), scene);
	if (!pl)
		return ;
	parse_position(*groups, &pl->pivot, scene);
	parse_normals(*(groups + 1), &pl->normal, scene);
	parse_color(*(groups + 2), &pl->color, scene);
	ft_cleanup(groups);
	pl->d = vec3_dot(&pl->normal, &pl->pivot);
	geom = ft_malloc(sizeof(t_geom), scene);
	if (!geom)
	{
		free(pl);
		return ;
	}
	geom->type = G_PLANE;
	geom->data = pl;
	scene_add_geom(scene, geom);
}

void	parse_plane(char *s, t_scene *scene)
{
	int	count;

	if (scene->had_error)
		return ;
	count = ft_count_words_by_space(s);
	if (count != 3)
	{
		scene->had_error = 1;
		printf(RED"ERROR:\n"RESET);
		printf(RED"\t|| "YELLOW"line: \""RESET);
		printf(BLACK"%.*s"YELLOW"\"\n"RESET, (int)ft_strlen(s) - 1, s);
		printf(RED"\t||\n\t|| "CYAN"The plane's definition should "RESET);
		printf(CYAN"have THREE groups of parameters.\n"RESET);
		printf(RED"\t|| "CYAN"{position} {orientation} {color}\n"RESET);
		printf(RED"\t|| "CYAN"Only "RED"%d"CYAN" were found.\n"RESET, count);
		return ;
	}
	set_plane(s, scene);
}
