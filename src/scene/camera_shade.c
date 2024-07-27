/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_shade.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:07:10 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/27 13:48:58 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scene.h"

static double	distance2light(t_vec3 *light_dir)
{
	double	radius;

	radius = vec3_length(light_dir);
	if (radius < 0.001)
		radius = 0.001;
	return (radius);
}

static void	geom_shade(t_hit_data *data, t_scene *scene)
{
	t_vec3		light_dir;
	t_ray		shadow_ray;
	t_hit_data	shadow_data;
	t_interval	shadow_int;
	double		r[2];

	vec3_substract(&scene->light.pivot, &data->p, &light_dir);
	r[0] = distance2light(&light_dir);
	ray_interval_bind(&shadow_int);
	shadow_int.create(&shadow_int, 0.001, r[0]);
	vec3_normalize(&light_dir, NULL);
	ray_set_direction(&shadow_ray, &light_dir);
	ray_set_origin(&shadow_ray, &data->p);
	if (!camera_ray_hit(&shadow_ray, &shadow_int, &shadow_data, \
			scene->geom_list))
	{
		r[1] = vec3_dot(&light_dir, &data->normal);
		if (r[1] < 0.0)
			r[1] = 0.0;
		vec3_copy(&data->color, &shadow_data.color);
		vec3_mult_const(&data->color, 100.0 * r[1] * scene->light.intencity / \
				r[0] / r[0]);
	}
	else
		vec3_init(&data->color, 0.0, 0.0, 0.0);
}

static t_color3	color_gradient(t_ray *ray, t_color3 *c, double intencity)
{
	t_vec3		unit_direction;
	t_color3	color;
	t_color3	white;
	double		a;

	vec3_init(&white, 1.0, 1.0, 1.0);
	vec3_normalize(&ray->direction, &unit_direction);
	a = 0.5 * (unit_direction.y + 1.0);
	color.x = ((1.0 - a) * white.x + a * c->x) * intencity;
	color.y = ((1.0 - a) * white.y + a * c->y) * intencity;
	color.z = ((1.0 - a) * white.z + a * c->z) * intencity;
	return (color);
}

static void	reflected_ray(t_ray *reflected_ray, t_hit_data *hit_data)
{
	t_vec3		reflected_dir;

	vec3_random_normalized(&reflected_dir);
	vec3_add(&reflected_dir, &hit_data->normal, NULL);
	ray_set_origin(reflected_ray, &hit_data->p);
	ray_set_direction(reflected_ray, &reflected_dir);
}

t_vec3	camera_ray_color(t_ray *ray, int bounce, t_scene *scene)
{
	t_color3	color;
	t_hit_data	hit_data;
	t_interval	ray_interval;
	t_ray		new_ray;

	if (bounce <= 0)
	{
		vec3_init(&color, 0.0, 0.0, 0.0);
		return (color);
	}
	ray_interval_bind(&ray_interval);
	ray_interval.create(&ray_interval, 0.0001, 1000.0);
	if (camera_ray_hit(ray, &ray_interval, &hit_data, scene->geom_list))
	{
		reflected_ray(&new_ray, &hit_data);
		color = camera_ray_color(&new_ray, bounce - 1, scene);
		vec3_mult(&color, &hit_data.color, NULL);
		geom_shade(&hit_data, scene);
		vec3_add(&color, &hit_data.color, NULL);
		vec3_mult_const(&color, 0.5);
		return (color);
	}
	color = color_gradient(ray, &scene->ambient.color, \
		scene->ambient.intencity);
	return (color);
}
