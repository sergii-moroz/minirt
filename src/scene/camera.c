/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:08:42 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/27 13:14:20 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scene.h"

void	camera_print(t_camera *camera)
{
	printf(YELLOW"CAMERA: {\n"RESET);
	printf(CYAN"  vfov: "BLACK"%f [deg]\n"RESET, camera->hfov);
	printf(CYAN"  focal length: "BLACK"%f\n"RESET, camera->focal_length);
	printf(CYAN"  viewport_height: "BLACK"%f\n"RESET, camera->viewport_height);
	printf(CYAN"  viewport_width: "BLACK"%f\n"RESET, camera->viewport_width);
	vec3_print(&camera->pivot, "position");
	vec3_print(&camera->u, "u");
	vec3_print(&camera->v, "v");
	vec3_print(&camera->w, "w");
	vec3_print(&camera->viewport_u, "viewport_u");
	vec3_print(&camera->viewport_v, "viewport_v");
	vec3_print(&camera->pixel_delta_u, "pixel_delta_u");
	vec3_print(&camera->pixel_delta_v, "pixel_delta_v");
	vec3_print(&camera->viewport_ul, "viewport_upper_left");
	vec3_print(&camera->pixel00, "pixel00");
	printf(YELLOW"}\n"RESET);
}

void	camera_set_pixel_center(t_point3 *pixel_center, t_camera *camera, \
			int i, int j)
{
	pixel_center->x = camera->pixel00.x \
		+ (i * camera->pixel_delta_u.x) + (j * camera->pixel_delta_v.x);
	pixel_center->y = camera->pixel00.y \
		+ (i * camera->pixel_delta_u.y) + (j * camera->pixel_delta_v.y);
	pixel_center->z = camera->pixel00.z \
		+ (i * camera->pixel_delta_u.z) + (j * camera->pixel_delta_v.z);
}

static void	collect(int *hit_anything, t_interval *ray_interval, \
		t_hit_data *hit_data)
{
	*hit_anything = 1;
	ray_interval->max = hit_data->t;
}

int	camera_ray_hit(t_ray *ray, t_interval *ray_interval, t_hit_data *hit_data, \
	t_list *geom_list)
{
	t_geom	*geom;
	int		hit_anything;

	hit_anything = 0;
	while (geom_list)
	{
		geom = geom_list->content;
		if ((geom->type == G_SPHERE) \
			&& sphere_hit((t_sphere *)geom->data, ray, ray_interval, hit_data))
			collect(&hit_anything, ray_interval, hit_data);
		else if ((geom->type == G_CYLINDER) \
			&& cylinder_hit(geom->data, ray, ray_interval, hit_data))
			collect(&hit_anything, ray_interval, hit_data);
		else if ((geom->type == G_PLANE) \
			&& plane_hit(geom->data, ray, ray_interval, hit_data))
			collect(&hit_anything, ray_interval, hit_data);
		else if ((geom->type == G_DISK) \
			&& disk_hit(geom->data, ray, ray_interval, hit_data))
			collect(&hit_anything, ray_interval, hit_data);
		geom_list = geom_list->next;
	}
	return (hit_anything);
}
