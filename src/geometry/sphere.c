/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:11:07 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 19:32:34 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

void	sphere_print(void *sp)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)sp;
	printf(YELLOW"SPHERE: {\n");
	vec3_print(&sphere->center, "center");
	printf(MAGENTA"  radius: "BLACK"%f\n", sphere->radius);
	vec3_print(&sphere->color, "color");
	printf(YELLOW"}\n"RESET);
}

void	sphere_set_color(t_sphere *sp, double r, double g, double b)
{
	sp->color.x = r;
	sp->color.y = g;
	sp->color.z = b;
}

static void	sphere_face_normal(t_hit_data *data, t_ray *ray, t_sphere *sp)
{
	vec3_substract(&data->p, &sp->center, &data->normal);
	vec3_mult_const(&data->normal, 1.0 / sp->radius);
	data->front_face = vec3_dot(&ray->direction, &data->normal) < 0.0;
	if (!data->front_face)
		vec3_invert(&data->normal);
}

int	sphere_hit(t_sphere *sp, t_ray *ray, t_interval *ray_interval, \
		t_hit_data *data)
{
	t_vec3	oc;
	double	a[3];
	double	discriminant;
	double	root;

	vec3_substract(&sp->center, &ray->origin, &oc);
	a[0] = vec3_length_squared(&ray->direction);
	a[1] = vec3_dot(&ray->direction, &oc);
	a[2] = vec3_length_squared(&oc) - sp->radius * sp->radius;
	discriminant = a[1] * a[1] - a[0] * a[2];
	if (discriminant < 0.0)
		return (0);
	discriminant = sqrt(discriminant);
	root = (a[1] - discriminant) / a[0];
	if (!ray_interval->surrounds(ray_interval, root))
	{
		root = (a[1] + discriminant) / a[0];
		if (!ray_interval->surrounds(ray_interval, root))
			return (0);
	}
	data->t = root;
	data->p = ray_at(ray, root);
	sphere_face_normal(data, ray, sp);
	data->color = sp->color;
	return (1);
}

	// Light simulation
	// ===============================
	// t_vec3	light_pos;
	// vec3_init(&light_pos, 4.0, 4.0, 4.0);
	// if (!is_shadow)
	// 	geom_shade(ray, ray_interval, data, &light_pos, geom_list);
	// =================================
	/*t_vec3	light_dir;
	double	light_intencity = 1.0;
	vec3_init(&light_dir, -1.0, -1.0, -1.0);
	vec3_invert(&light_dir);
	double	d = vec3_dot(&data->normal, &light_dir);
	if (d < 0.0)
		d = 0.0;
	vec3_mult_const(&data->color, d * light_intencity);//*/
