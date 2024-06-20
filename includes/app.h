/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:10:25 by smoroz            #+#    #+#             */
/*   Updated: 2024/06/06 13:30:59 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

# define WIDTH 512
# define HEIGHT 512
# define APP_TITEL "miniRT: olanokhi & smoroz"
# define RSIZE 64

# include <stdlib.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include "minilibx_events.h"
# include "minilibx_keys.h"
# include "common.h"

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
	int		hilbert_idx;
	int		need_update;
}			t_app;

//	app.c
void	app_init(t_app *app);

//	hooks.c
int	destroy_window(t_app *app);
int	keys_hook(int keycode, t_app *app);

// update.c
int	update(t_app *app);

#endif
