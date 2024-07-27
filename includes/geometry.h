/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:16:17 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/27 14:07:02 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# define G_SPHERE 1
# define G_CYLINDER 2
# define G_PLANE 3
# define G_DISK 4

# include "vec3.h"
# include "ray.h"
# include "interval.h"
# include "../libft/libft.h"

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	t_color3	color;
	void		(*print)(void *);
	int			(*hit)(void *);
}				t_sphere;

typedef struct s_cylinder
{
	t_point3	pivot;
	t_vec3		axis;
	double		radius;
	double		height;
	t_color3	color;
}				t_cylinder;

typedef struct s_plane
{
	t_point3	pivot;
	t_vec3		normal;
	t_color3	color;
	double		d;
	double		radius;
}				t_plane;

typedef struct s_geom
{
	int		type;
	void	*data;
}			t_geom;

typedef struct s_hit_data
{
	t_point3	p;
	t_vec3		normal;
	double		t;
	int			front_face;
	t_color3	color;
}				t_hit_data;

typedef struct s_sq_root
{
	double	a;
	double	h;
	double	c;
	double	k;
	double	l;
	double	m;
	double	discriminant;
}			t_sq_root;

//			sphere.c
void		sphere_print(void *sp);
int			sphere_hit(t_sphere *sp, t_ray *ray, t_interval *interval, \
				t_hit_data *data);
void		sphere_set_color(t_sphere *sp, double r, double g, double b);
// static void	sphere_face_normal(t_hit_data *data, t_ray *ray, t_sphere *sp);

//			cylinder.c
void		cylinder_print(void *cy);
int			cylinder_hit(t_cylinder *cy, t_ray *ray, t_interval *ray_interval, \
				t_hit_data *data);
// static void	cylinder_face_normal(t_hit_data *data, t_ray *ray,
//				t_cylinder *cy, double m);
// static t_sq_root	solve_sq_factors(t_ray *ray, t_cylinder *cy);
// void		cylinder_set_pivot(t_cylinder *cy, double x, double y, double z);
// void		cylinder_set_color(t_cylinder *cy, double r, double g, double b);
// void		cylinder_set_axis(t_cylinder *cy, double x, double y, double z);

//			plane.c
void		plane_print(void *pl);
void		plane_set_pivot(t_plane *pl, double x, double y, double z);
void		plane_set_color(t_plane *pl, double r, double g, double b);
void		plane_set_normal(t_plane *pl, double x, double y, double z);

//			plane_hit.c
int			plane_hit(t_plane *pl, t_ray *ray, t_interval *ray_interval, \
				t_hit_data *data);
int			disk_hit(t_plane *pl, t_ray *ray, t_interval *ray_interval, \
				t_hit_data *data);
// static void	plane_face_normal(t_hit_data *data, t_ray *ray, t_plane *pl);
#endif
