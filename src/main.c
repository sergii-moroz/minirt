/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:16:03 by smoroz            #+#    #+#             */
/*   Updated: 2024/06/06 13:32:55 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	char	**s;
	t_app	app;

	s = argv;
	if (argc == 1)
	{
		printf("ERROR: Scene description file isn't specified\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		printf("ERROR: Too many arguments\n");
		exit(EXIT_FAILURE);
	}
	printf("file_name: \"%s\"\n", argv[1]);
	check_input(argv[1]);
	app_init(&app);
	mlx_loop(app.mlx);
	return (EXIT_SUCCESS);
}
