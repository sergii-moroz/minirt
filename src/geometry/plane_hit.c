/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:01:33 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/27 14:10:55 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

static void	plane_face_normal(t_hit_data *data, t_ray *ray, t_plane *pl)
{
	vec3_copy(&pl->normal, &data->normal);
	data->front_face = vec3_dot(&ray->direction, &data->normal) < 0.0;
	if (!data->front_face)
		vec3_invert(&data->normal);
}

int	plane_hit(t_plane *pl, t_ray *ray, t_interval *ray_interval, \
		t_hit_data *data)
{
	double	denom;
	double	t;

	denom = vec3_dot(&pl->normal, &ray->direction);
	if (fabs(denom) < 1.0e-8)
		return (0);
	t = (pl->d - vec3_dot(&pl->normal, &ray->origin)) / denom;
	if (!ray_interval->contains(ray_interval, t))
		return (0);
	data->t = t;
	data->p = ray_at(ray, t);
	data->color = pl->color;
	plane_face_normal(data, ray, pl);
	return (1);
}

int	disk_hit(t_plane *pl, t_ray *ray, t_interval *ray_interval, \
		t_hit_data *data)
{
	double		denom;
	double		t;
	t_point3	p;

	denom = vec3_dot(&pl->normal, &ray->direction);
	if (fabs(denom) < 1.0e-8)
		return (0);
	t = (pl->d - vec3_dot(&pl->normal, &ray->origin)) / denom;
	if (!ray_interval->contains(ray_interval, t))
		return (0);
	p = ray_at(ray, t);
	vec3_substract(&p, &pl->pivot, NULL);
	if (vec3_length(&p) > pl->radius)
		return (0);
	data->t = t;
	data->p = ray_at(ray, t);
	data->color = pl->color;
	plane_face_normal(data, ray, pl);
	return (1);
}
