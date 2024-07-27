/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:10:25 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/27 14:00:38 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

# define ASPECT_RATIO 1.777778
# define WIDTH 600
# define SAMPLES 16
# define BOUNCES 4
# define APP_TITEL "miniRT: olanokhi & smoroz"

# include <stdlib.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include "minilibx_events.h"
# include "minilibx_keys.h"
# include "common.h"
# include "scene.h"
# include "ray.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels;
	int		bpp;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_app
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		need_update;
	int		height;
	int		samples_per_pixel;
	int		bounces;
	t_scene	scene;
}			t_app;

//		app.c
void	app_init(t_app *app);
// static int	app_height(void);
// static void	data_init(t_app *app);
// static void	events_init(t_app *app);

//		hooks.c
int		destroy_window(t_app *app);
int		keys_hook(int keycode, t_app *app);

//		update.c
int		update(t_app *app);
// static void	ft_pixel_put(t_img *img, int x, int y, int color);
// static void	handle_pixel(int x, int y, t_app *app);
// static void	render_camera_view(t_app *app);

#endif
