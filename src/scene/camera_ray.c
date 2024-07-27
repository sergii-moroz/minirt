/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:42:00 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/27 13:53:30 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scene.h"

static t_point3	sample_square(void)
{
	t_point3	v;

	v.x = random_double() - 0.5;
	v.y = random_double() - 0.5;
	v.z = 0.0;
	return (v);
}

void	camera_set_ray_direction(t_vec3 *dir, t_point3 *pixel_center, \
		t_camera *camera)
{
	dir->x = pixel_center->x - camera->pivot.x;
	dir->y = pixel_center->y - camera->pivot.y;
	dir->z = pixel_center->z - camera->pivot.z;
}

t_ray	camera_get_ray(int x, int y, t_camera *camera)
{
	t_ray		ray;
	t_point3	offset;
	t_point3	pixel_sample;
	t_vec3		ray_direction;

	offset = sample_square();
	pixel_sample.x = camera->pixel00.x \
		+ ((x + offset.x) * camera->pixel_delta_u.x) \
		+ ((y + offset.y) * camera->pixel_delta_v.x);
	pixel_sample.y = camera->pixel00.y \
		+ ((x + offset.x) * camera->pixel_delta_u.y) \
		+ ((y + offset.y) * camera->pixel_delta_v.y);
	pixel_sample.z = camera->pixel00.z \
		+ ((x + offset.x) * camera->pixel_delta_u.z) \
		+ ((y + offset.y) * camera->pixel_delta_v.z);
	camera_set_ray_direction(&ray_direction, &pixel_sample, camera);
	ray_set_origin(&ray, &camera->pivot);
	ray_set_direction(&ray, &ray_direction);
	return (ray);
}
