/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:59:44 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/30 15:59:50 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void	set_sphere(char *s, t_scene *scene)
{
	t_sphere	*sp;
	t_geom		*geom;
	char		**groups;

	if (scene->had_error)
		return ;
	groups = ft_split_by_space(s);
	sp = ft_malloc(sizeof(t_sphere), scene);
	if (!sp)
		return ;
	parse_position(*groups, &sp->center, scene);
	parse_color(*(groups + 2), &sp->color, scene);
	parse_radius(*(groups + 1), &sp->radius, scene);
	ft_cleanup(groups);
	geom = ft_malloc(sizeof(t_geom), scene);
	if (!geom)
	{
		free(sp);
		return ;
	}
	geom->type = G_SPHERE;
	geom->data = sp;
	scene_add_geom(scene, geom);
}

void	parse_sphere(char *s, t_scene *scene)
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
		printf(RED"\t||\n\t|| "CYAN"The sphere's definition should "RESET);
		printf(CYAN"have THREE groups of parameters.\n"RESET);
		printf(RED"\t|| "CYAN"{position} {diameter} {color}\n"RESET);
		printf(RED"\t|| "CYAN"Only "RED"%d"CYAN" were found.\n"RESET, count);
		return ;
	}
	set_sphere(s, scene);
}
