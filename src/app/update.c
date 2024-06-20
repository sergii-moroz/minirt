/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:59:38 by smoroz            #+#    #+#             */
/*   Updated: 2024/06/05 16:21:15 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/app.h"
#include "../../includes/hilbert_curve.h"
#include "../../includes/common.h"

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
	int	color;
	int	order;
	int	blue;

	/* ADD HERE REAL RAY TRANCING */
	// c = screen2coord(x, y, vars);
	// color = color_manager(n, vars);
	order = WIDTH / RSIZE;
	blue = 255 * app->hilbert_idx / order / order;
	color = create_trgb(0, 255, 255 - blue, blue);
	ft_pixel_put(&app->img, x, y, color);
}

static void	handle_rect(int x, int y, t_app *app)
{
	int	dx;
	int	dy;

	dy = 0;
	while (dy < RSIZE)
	{
		dx = 0;
		while (dx < RSIZE)
		{
			handle_pixel(x + dx, y - dy, app);
			dx++;
		}
		dy++;
	}
}

static void	render_hilbert(t_app *app)
{
	int			order;
	t_int_point	point;

	mlx_clear_window(app->mlx, app->win);
	order = WIDTH / RSIZE;
	point = hindex2xy(app->hilbert_idx, order);
	point.y = -(point.y * RSIZE) + HEIGHT - 1;
	point.x = point.x * RSIZE;
	if (app->hilbert_idx < order * order)
	{
		handle_rect(point.x, point.y, app);
		app->hilbert_idx++;
	}
	else
	{
		app->hilbert_idx = 0;
		app->need_update = 0;
	}
}

int	update(t_app *app)
{
	if (app->need_update)
	{
		render_hilbert(app);
		mlx_put_image_to_window(app->mlx, app->win, app->img.img_ptr, 0, 0);
	}
	return (0);
}
