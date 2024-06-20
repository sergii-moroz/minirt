/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:08:47 by smoroz            #+#    #+#             */
/*   Updated: 2024/06/06 13:24:51 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/app.h"

static void	data_init(t_app *app)
{
	app->hilbert_idx = 0;
	app->need_update = 1;
}

static void	events_init(t_app *app)
{
	mlx_hook(app->win, ON_KEYDOWN, 0, keys_hook, app);
	mlx_hook(app->win, ON_DESTROY, 0, destroy_window, app);
	mlx_loop_hook(app->mlx, update, app);
}

void	app_init(t_app *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		error_fatal("ERROR: mlx_init: ");
	app->win = mlx_new_window(app->mlx, WIDTH, HEIGHT, APP_TITEL);
	if (!app->win)
		error_fatal("ERROR: mlx_new_window: ");
	app->img.img_ptr = mlx_new_image(app->mlx, WIDTH, HEIGHT);
	if (!app->img.img_ptr)
	{
		mlx_destroy_window(app->mlx, app->win);
		error_fatal("ERROR: mlx_new_image: ");
	}
	app->img.img_pixels = mlx_get_data_addr(app->img.img_ptr,
		&app->img.bpp,
		&app->img.line_length,
		&app->img.endian);
	data_init(app);
	events_init(app);
}
