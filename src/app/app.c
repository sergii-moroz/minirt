/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:08:47 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 17:38:05 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/app.h"

static int	app_height(void)
{
	int	height;

	height = WIDTH / (ASPECT_RATIO);
	if (height <= 0)
		height = 1;
	return (height);
}

static void	data_init(t_app *app)
{
	app->need_update = 1;
	app->height = app_height();
	camera_init_2(&app->scene.camera, WIDTH, app->height);
	scene_print(&app->scene);
	app->samples_per_pixel = SAMPLES;
	app->bounces = BOUNCES;
}

static void	events_init(t_app *app)
{
	mlx_hook(app->win, ON_KEYDOWN, 0, keys_hook, app);
	mlx_hook(app->win, ON_DESTROY, 0, destroy_window, app);
	mlx_loop_hook(app->mlx, update, app);
}

void	app_init(t_app *app)
{
	data_init(app);
	app->mlx = mlx_init();
	if (!app->mlx)
		error_fatal("ERROR: mlx_init: ");
	app->win = mlx_new_window(app->mlx, WIDTH, app->height, APP_TITEL);
	if (!app->win)
		error_fatal("ERROR: mlx_new_window: ");
	app->img.img_ptr = mlx_new_image(app->mlx, WIDTH, app->height);
	if (!app->img.img_ptr)
	{
		mlx_destroy_window(app->mlx, app->win);
		error_fatal("ERROR: mlx_new_image: ");
	}
	app->img.img_pixels = mlx_get_data_addr(app->img.img_ptr,
			&app->img.bpp,
			&app->img.line_length,
			&app->img.endian);
	events_init(app);
}
