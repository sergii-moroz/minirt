/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:50:14 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/27 14:09:49 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

void	plane_print(void *pl)
{
	t_plane	*plane;

	plane = (t_plane *)pl;
	printf(YELLOW"PLANE: {\n");
	vec3_print(&plane->pivot, "pivot");
	vec3_print(&plane->normal, "normal");
	vec3_print(&plane->color, "color");
	printf(YELLOW"}\n"RESET);
}

void	plane_set_color(t_plane *pl, double r, double g, double b)
{
	vec3_init(&pl->color, r, g, b);
}

void	plane_set_normal(t_plane *pl, double x, double y, double z)
{
	vec3_init(&pl->normal, x, y, z);
	pl->d = vec3_dot(&pl->normal, &pl->pivot);
}

void	plane_set_pivot(t_plane *pl, double x, double y, double z)
{
	vec3_init(&pl->pivot, x, y, z);
	pl->d = vec3_dot(&pl->normal, &pl->pivot);
}
