/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:13:52 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/27 15:55:32 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/app.h"

static void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * img->line_length + x * (img->bpp / 8);
	dst = img->img_pixels + offset;
	*(unsigned *)dst = color;
}

static void	handle_pixel(int x, int y, t_app *app)
{
	t_color3	c[2];
	t_point3	pixel_center;
	t_vec3		ray_direction;
	t_ray		ray;
	int			i;

	camera_set_pixel_center(&pixel_center, &app->scene.camera, x, y);
	camera_set_ray_direction(&ray_direction, &pixel_center, &app->scene.camera);
	ray_set_origin(&ray, &app->scene.camera.pivot);
	ray_set_direction(&ray, &ray_direction);
	c[0] = camera_ray_color(&ray, app->bounces, &app->scene);
	i = 1;
	while (i < app->samples_per_pixel)
	{
		ray = camera_get_ray(x, y, &app->scene.camera);
		c[1] = camera_ray_color(&ray, app->bounces, &app->scene);
		vec3_add(c, c + 1, NULL);
		i++;
	}
	vec3_mult_const(c, 1.0 / app->samples_per_pixel);
	ft_pixel_put(&app->img, x, y, create_trgb(0.0, c[0].x, c[0].y, c[0].z));
}

static void	render_camera_view(t_app *app)
{
	int	x;
	int	y;

	y = 0;
	while (y < app->height)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, app);
			x++;
		}
		y++;
	}
}

int	update(t_app *app)
{
	if (app->need_update)
	{
		render_camera_view(app);
		mlx_put_image_to_window(app->mlx, app->win, app->img.img_ptr, 0, 0);
		app->need_update = 0;
	}
	return (0);
}
