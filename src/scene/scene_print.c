/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:17:43 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 20:23:06 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scene.h"

static void	ambient_print(t_ambient *ambient)
{
	printf(YELLOW"AMBIENT: {\n"RESET);
	printf(CYAN"  intencity: "BLACK"%f\n"RESET, ambient->intencity);
	vec3_print(&ambient->color, "color");
	printf(YELLOW"}\n"RESET);
}

static void	light_print(t_light *light)
{
	printf(YELLOW"LIGHT: {\n"RESET);
	vec3_print(&light->pivot, "position");
	printf(CYAN"  intencity: "BLACK"%f\n"RESET, light->intencity);
	vec3_print(&light->color, "color");
	printf(YELLOW"}\n"RESET);
}

static void	print_geom_list(void *node)
{
	t_geom		*geom;

	geom = (t_geom *)node;
	if (geom->type == G_SPHERE)
		sphere_print(geom->data);
	else if (geom->type == G_CYLINDER)
		cylinder_print(geom->data);
	else if (geom->type == G_PLANE)
		plane_print(geom->data);
}

void	scene_print(t_scene *sc)
{
	printf(GREEN"=== SCENE START === \n");
	camera_print(&sc->camera);
	ambient_print(&sc->ambient);
	light_print(&sc->light);
	ft_lstiter(sc->geom_list, print_geom_list);
	printf(GREEN"=== SCENE END ===\n"RESET);
}
