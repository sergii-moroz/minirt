/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:22:59 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/27 14:08:29 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

// # include "camera.h"
# include "vec3.h"
# include "ray.h"
# include "interval.h"
# include "geometry.h"
# include "../libft/libft.h"

typedef struct s_ambient
{
	t_color3	color;
	double		intencity;
}				t_ambient;

typedef struct s_light
{
	t_point3	pivot;
	t_color3	color;
	double		intencity;
}				t_light;

typedef struct s_camera
{
	double		hfov;
	double		focal_length;
	double		viewport_width;
	double		viewport_height;
	t_point3	pivot;
	t_point3	lookat;
	t_vec3		vup;
	t_vec3		w;
	t_vec3		u;
	t_vec3		v;
	t_vec3		viewport_u;
	t_vec3		viewport_v;
	t_vec3		pixel_delta_u;
	t_vec3		pixel_delta_v;
	t_vec3		viewport_ul;
	t_vec3		pixel00;
}				t_camera;

typedef struct s_scene
{
	int			had_error;
	int			camera_count;
	int			light_count;
	int			ambient_count;
	t_camera	camera;
	t_light		light;
	t_ambient	ambient;
	t_list		*geom_list;
}	t_scene;

//		scene.c
void	scene_add_geom(t_scene *sc, t_geom *geom);
void	scene_free(t_scene *sc);
// static void	geom_list_free(void *node);

//		scene_print.c
void	scene_print(t_scene *sc);
// static void	ambient_print(t_ambient *ambient);
// static void	light_print(t_light *light);
// static void	print_geom_list(void *node);

//		camera.c
void	camera_print(t_camera *camera);
void	camera_set_pixel_center(t_point3 *pixel_center, t_camera *camera, \
			int i, int j);
int		camera_ray_hit(t_ray *ray, t_interval *ray_interval, \
			t_hit_data *hit_data, t_list *geom_list);
// static void	collect(int *hit_anything, t_interval *ray_interval,
//			t_hit_data *hit_data)

//		camera_init.c
void	camera_init_2(t_camera *camera, int width, int height);
// static double	degree2radian(double deg);
// static void	set_viewport_upper_left(t_camera *camera);
// static void	set_pixel00(t_camera *camera);

//		camera_ray.c
void	camera_set_ray_direction(t_vec3 *dir, t_point3 *pixel_center, \
			t_camera *camera);
t_ray	camera_get_ray(int x, int y, t_camera *camera);
// static t_point3	sample_square(void);

//		camera_shade.c
t_vec3	camera_ray_color(t_ray *ray, int bounces, t_scene *scene);
// static t_color3	color_gradient(t_ray *ray, t_color3 *c, double intencity);
// static void	reflected_ray(t_ray *reflected_ray, t_hit_data *hit_data);
// static void	geom_shade(t_hit_data *data, t_scene *scene);

#endif
