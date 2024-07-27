/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set_cylinder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:10:59 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 17:19:07 by smoroz           ###   ########.fr       */
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
		return ;
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

void	set_cylinder(char *line, t_scene *sc)
{
	float		tmp_f;
	int			i;
	t_cylinder	*cy;

	if (sc->had_error)
		return ;
	cy = ft_malloc(sizeof(t_cylinder), sc);
	if (!cy)
		return ;
	i = 0;
	triple_float_handler(line, &cy->pivot, &i);
	i = get_next_digit(line, i);
	triple_float_handler(line, &cy->axis, &i);
	i = get_next_digit(line, i);
	tmp_f = ft_atof(line + i, &i);
	cy->radius = (double)tmp_f / 2;
	i = get_next_digit(line, i);
	tmp_f = ft_atof(line + i, &i);
	cy->height = (double)tmp_f;
	i = get_next_digit(line, i);
	triple_int_handler(line, &cy->color, &i);
	add_cylinder(sc, cy);
}
