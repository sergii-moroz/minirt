/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:38:43 by smoroz            #+#    #+#             */
/*   Updated: 2024/06/04 12:13:57 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/app.h"

int	destroy_window(t_app *app)
{
	mlx_destroy_image(app->mlx, app->img.img_ptr);
	mlx_destroy_window(app->mlx, app->win);
	exit(EXIT_SUCCESS);
}

int	keys_hook(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
		destroy_window(app);
	return (EXIT_SUCCESS);
}
