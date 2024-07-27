/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set_geoms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:40:38 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/27 14:11:30 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	set_plane(char *line, t_scene *sc)
{
	int		i;
	t_plane	*pl;
	t_geom	*geom;

	pl = ft_malloc(sizeof(t_plane), sc);
	if (!pl)
		return ;
	i = 0;
	triple_float_handler(line, &pl->pivot, &i);
	i = get_next_digit(line, i);
	triple_float_handler(line, &pl->normal, &i);
	i = get_next_digit(line, i);
	triple_int_handler(line, &pl->color, &i);
	pl->d = vec3_dot(&pl->normal, &pl->pivot);
	geom = ft_malloc(sizeof(t_geom), sc);
	if (!geom)
	{
		free(pl);
		return ;
	}
	geom->type = G_PLANE;
	geom->data = pl;
	scene_add_geom(sc, geom);
}

void	set_sphere(char *line, t_scene *sc)
{
	float		tmp_f;
	int			i;
	t_sphere	*sp;
	t_geom		*geom;

	sp = ft_malloc(sizeof(t_sphere), sc);
	if (!sp)
		return ;
	i = 0;
	triple_float_handler(line, &sp->center, &i);
	i = get_next_digit(line, i);
	tmp_f = ft_atof(line + i, &i);
	sp->radius = (double)tmp_f / 2.0;
	i = get_next_digit(line, i);
	triple_int_handler(line, &sp->color, &i);
	geom = ft_malloc(sizeof(t_geom), sc);
	if (!geom)
	{
		free(sp);
		return ;
	}
	geom->type = G_SPHERE;
	geom->data = sp;
	scene_add_geom(sc, geom);
}
