/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:16:03 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 15:34:38 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	check_leaks(void)
{
	system("leaks miniRT");
}

int	main(int argc, char **argv)
{
	t_app	app;
	t_scene	scene;

	atexit(check_leaks);
	if (!is_args_valid(argc, argv))
		return (EXIT_FAILURE);
	// else
	// 	printf(GREEN"Args is valid!\n"RESET);
	if (!is_parse_ok(argv[1], &scene))
	{
		scene_free(&scene);
		return (EXIT_FAILURE);
	}
	// else
	// 	printf(GREEN"Scene is valid!\n"RESET);
	app.scene = scene;
	app_init(&app);
	mlx_loop(app.mlx);
	scene_free(&app.scene);
	return (EXIT_SUCCESS);
}
