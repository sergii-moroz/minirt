/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:22:25 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/30 15:58:26 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void	scene_add_cydisk1(t_scene *sc, t_cylinder *cy)
{
	t_geom	*geom;
	t_plane	*pl;

	if (sc->had_error)
		return ;
	pl = ft_malloc(sizeof(t_plane), sc);
	if (!pl)
		return ;
	plane_set_pivot(pl, cy->pivot.x, cy->pivot.y, cy->pivot.z);
	plane_set_normal(pl, -cy->axis.x, -cy->axis.y, -cy->axis.z);
	plane_set_color(pl, cy->color.x, cy->color.y, cy->color.z);
	pl->radius = cy->radius;
	geom = ft_malloc(sizeof(t_geom), sc);
	if (!geom)
	{
		free(pl);
		return ;
	}
	geom->type = G_DISK;
	geom->data = pl;
	scene_add_geom(sc, geom);
}

static void	scene_add_cydisk2(t_scene *sc, t_cylinder *cy)
{
	t_geom		*geom;
	t_plane		*pl;
	t_point3	p;

	if (sc->had_error)
		return ;
	vec3_copy(&cy->axis, &p);
	vec3_mult_const(&p, cy->height);
	vec3_add(&p, &cy->pivot, NULL);
	pl = ft_malloc(sizeof(t_plane), sc);
	if (!pl)
		return ;
	plane_set_pivot(pl, p.x, p.y, p.z);
	plane_set_normal(pl, cy->axis.x, cy->axis.y, cy->axis.z);
	plane_set_color(pl, cy->color.x, cy->color.y, cy->color.z);
	pl->radius = cy->radius;
	geom = ft_malloc(sizeof(t_geom), sc);
	if (!geom)
	{
		free(pl);
		return ;
	}
	geom->type = G_DISK;
	geom->data = pl;
	scene_add_geom(sc, geom);
}

static void	add_cylinder(t_scene *sc, t_cylinder *cy)
{
	t_geom	*geom;

	if (sc->had_error)
	{
		free(cy);
		return ;
	}
	geom = ft_malloc(sizeof(t_geom), sc);
	if (!geom)
	{
		free(cy);
		return ;
	}
	geom->type = G_CYLINDER;
	geom->data = cy;
	scene_add_geom(sc, geom);
	scene_add_cydisk1(sc, cy);
	scene_add_cydisk2(sc, cy);
}

static void	set_cylinder(char *s, t_scene *scene)
{
	t_cylinder	*cy;
	char		**groups;

	if (scene->had_error)
		return ;
	groups = ft_split_by_space(s);
	cy = ft_malloc(sizeof(t_cylinder), scene);
	if (!cy)
		return ;
	parse_position(*groups, &cy->pivot, scene);
	parse_normals(*(groups + 1), &cy->axis, scene);
	parse_radius(*(groups + 2), &cy->radius, scene);
	parse_height(*(groups + 3), &cy->height, scene);
	parse_color(*(groups + 4), &cy->color, scene);
	ft_cleanup(groups);
	add_cylinder(scene, cy);
}

void	parse_cylinder(char *s, t_scene *scene)
{
	int	count;

	if (scene->had_error)
		return ;
	count = ft_count_words_by_space(s);
	if (count != 5)
	{
		scene->had_error = 1;
		printf(RED"ERROR:\n"RESET);
		printf(RED"\t|| "YELLOW"line: \""RESET);
		printf(BLACK"%.*s"YELLOW"\"\n"RESET, (int)ft_strlen(s) - 1, s);
		printf(RED"\t||\n\t|| "CYAN"The cylinder's definition should "RESET);
		printf(CYAN"have FIVE spaces separated groups of parameters.\n"RESET);
		printf(RED"\t|| "CYAN"{position} {orientation} {diameter} "RESET);
		printf(CYAN"{height} {color}.\n"RESET);
		printf(RED"\t|| "CYAN"Only "RED"%d"CYAN" were found.\n"RESET, count);
		return ;
	}
	set_cylinder(s, scene);
}
