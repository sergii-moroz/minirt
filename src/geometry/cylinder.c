/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:39:51 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 20:12:46 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

void	cylinder_print(void *cy)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)cy;
	printf(YELLOW"CYLINDER: {\n");
	vec3_print(&cylinder->pivot, "pivot");
	vec3_print(&cylinder->axis, "axis");
	vec3_print(&cylinder->color, "color");
	printf(MAGENTA"  radius: "BLACK"%f\n", cylinder->radius);
	printf(MAGENTA"  height: "BLACK"%f\n", cylinder->height);
	printf(YELLOW"}\n"RESET);
}

static void	cylinder_face_normal(t_hit_data *data, t_ray *ray, \
		t_cylinder *cy,	double m)
{
	t_vec3	temp;

	vec3_substract(&data->p, &cy->pivot, &data->normal);
	vec3_copy(&cy->axis, &temp);
	vec3_mult_const(&temp, m);
	vec3_substract(&data->normal, &temp, NULL);
	vec3_normalize(&data->normal, NULL);
	data->front_face = vec3_dot(&ray->direction, &data->normal) < 0.0;
	if (!data->front_face)
		vec3_invert(&data->normal);
}

static t_sq_root	solve_sq_factors(t_ray *ray, t_cylinder *cy)
{
	t_sq_root	sq;
	t_vec3		oc;

	ft_memset(&sq, 0, sizeof(t_sq_root));
	vec3_substract(&ray->origin, &cy->pivot, &oc);
	sq.k = vec3_dot(&ray->direction, &cy->axis);
	sq.l = vec3_dot(&oc, &cy->axis);
	sq.a = vec3_length_squared(&ray->direction) - sq.k * sq.k;
	sq.h = -(vec3_dot(&ray->direction, &oc) - sq.k * sq.l);
	sq.c = vec3_length_squared(&oc) - sq.l * sq.l - cy->radius * cy->radius;
	sq.discriminant = sq.h * sq.h - sq.a * sq.c;
	return (sq);
}

int	cylinder_hit(t_cylinder *cy, t_ray *ray, t_interval *ray_interval, \
		t_hit_data *data)
{
	t_sq_root	sq;
	double		root;

	sq = solve_sq_factors(ray, cy);
	if (sq.discriminant < 0.0)
		return (0);
	sq.discriminant = sqrt(sq.discriminant);
	root = (sq.h - sq.discriminant) / sq.a;
	sq.m = sq.k * root + sq.l;
	if (!ray_interval->surrounds(ray_interval, root) || \
		(sq.m < 0.0 || sq.m > cy->height))
	{
		root = (sq.h + sq.discriminant) / sq.a;
		sq.m = sq.k * root + sq.l;
		if (!ray_interval->surrounds(ray_interval, root) || \
			(sq.m < 0.0 || sq.m > cy->height))
			return (0);
	}
	data->t = root;
	data->p = ray_at(ray, root);
	data->color = cy->color;
	cylinder_face_normal(data, ray, cy, sq.m);
	return (1);
}

// t_vec3		oc;
	// double	k, l, m;
	// double	a;
	// double	h;
	// double	c;
	//double	discriminant;

	//vec3_substract(&cy->pivot, &ray->origin, &oc);
	/*vec3_substract(&ray->origin, &cy->pivot, &oc);
	sq.k = vec3_dot(&ray->direction, &cy->axis);
	sq.l = vec3_dot(&oc, &cy->axis);
	sq.a = vec3_length_squared(&ray->direction) - sq.k * sq.k;
	sq.h = -(vec3_dot(&ray->direction, &oc) - sq.k * sq.l);
	sq.c = vec3_length_squared(&oc) - sq.l * sq.l - cy->radius * cy->radius;
	sq.discriminant = sq.h * sq.h - sq.a * sq.c;*/

	// Light simulation
	/*t_vec3	light_dir;
	double	light_intencity = 1.0;
	vec3_init(&light_dir, -1.0, -1.0, -1.0);
	vec3_invert(&light_dir);
	double	d = vec3_dot(&data->normal, &light_dir);
	if (d < 0.0)
		d = 0.0;
	vec3_mult_const(&data->color, d * light_intencity);*/
	// ==============================
	// Light simulation
	// t_vec3	light_pos;
	// vec3_init(&light_pos, 4.0, 4.0, 4.0);
	// if(!is_shadow)
	// 	geom_shade(ray, ray_interval, data, &light_pos, geom_list);
	// ==============================

/*void	cylinder_set_color(t_cylinder *cy, double r, double g, double b)
{
	vec3_init(&cy->color, r, g, b);
}

void	cylinder_set_axis(t_cylinder *cy, double x, double y, double z)
{
	vec3_init(&cy->axis, x, y, z);
}

void	cylinder_set_pivot(t_cylinder *cy, double x, double y, double z)
{
	vec3_init(&cy->pivot, x, y , z);
}*/
