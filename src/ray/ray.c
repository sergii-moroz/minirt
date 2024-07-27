/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:08:49 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 18:45:48 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ray.h"

t_vec3	ray_at(t_ray *ray, double t)
{
	t_vec3	v;

	v.x = ray->origin.x + t * ray->direction.x;
	v.y = ray->origin.y + t * ray->direction.y;
	v.z = ray->origin.z + t * ray->direction.z;
	return (v);
}

void	ray_set_origin(t_ray *ray, t_point3 *point)
{
	ray->origin.x = point->x;
	ray->origin.y = point->y;
	ray->origin.z = point->z;
}

void	ray_set_direction(t_ray *ray, t_vec3 *dir)
{
	ray->direction.x = dir->x;
	ray->direction.y = dir->y;
	ray->direction.z = dir->z;
}
