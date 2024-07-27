/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:35:18 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 20:37:51 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scene.h"

static double	degree2radian(double deg)
{
	return (deg * M_PI / 180.0);
}

static void	set_viewport_upper_left(t_camera *camera)
{
	double	x;
	double	y;
	double	z;

	x = camera->pivot.x - camera->focal_length * camera->w.x \
		- 0.5 * (camera->viewport_u.x + camera->viewport_v.x);
	y = camera->pivot.y - camera->focal_length * camera->w.y \
		- 0.5 * (camera->viewport_u.y + camera->viewport_v.y);
	z = camera->pivot.z - camera->focal_length * camera->w.z \
		- 0.5 * (camera->viewport_u.z + camera->viewport_v.z);
	vec3_init(&camera->viewport_ul, x, y, z);
}

static void	set_pixel00(t_camera *camera)
{
	double	x;
	double	y;
	double	z;

	x = camera->viewport_ul.x \
		+ 0.5 * (camera->pixel_delta_u.x + camera->pixel_delta_v.x);
	y = camera->viewport_ul.y \
		+ 0.5 * (camera->pixel_delta_u.y + camera->pixel_delta_v.y);
	z = camera->viewport_ul.z \
		+ 0.5 * (camera->pixel_delta_u.z + camera->pixel_delta_v.z);
	vec3_init(&camera->pixel00, x, y, z);
}

void	camera_init_2(t_camera *camera, int width, int height)
{
	double	theta;
	double	h;

	vec3_init(&camera->vup, 0.0, 1.0, 0.0);
	theta = degree2radian(camera->hfov);
	h = tanf(theta / 2.0);
	camera->focal_length = 4.0;
	camera->viewport_width = 2.0 * h * camera->focal_length;
	camera->viewport_height = camera->viewport_width * \
		(double)height / (double)width;
	vec3_cross(&camera->vup, &camera->w, &camera->u);
	vec3_normalize(&camera->u, NULL);
	vec3_cross(&camera->w, &camera->u, &camera->v);
	vec3_copy(&camera->u, &camera->viewport_u);
	vec3_mult_const(&camera->viewport_u, camera->viewport_width);
	vec3_copy(&camera->v, &camera->viewport_v);
	vec3_mult_const(&camera->viewport_v, -camera->viewport_height);
	vec3_copy(&camera->viewport_u, &camera->pixel_delta_u);
	vec3_mult_const(&camera->pixel_delta_u, 1.0 / width);
	vec3_copy(&camera->viewport_v, &camera->pixel_delta_v);
	vec3_mult_const(&camera->pixel_delta_v, 1.0 / height);
	set_viewport_upper_left(camera);
	set_pixel00(camera);
}
