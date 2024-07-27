/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:04:18 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 20:24:13 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scene.h"

static void	geom_list_free(void *node)
{
	t_geom	*geom;

	geom = (t_geom *)node;
	free(geom->data);
	free(geom);
}

void	scene_free(t_scene *sc)
{
	ft_lstclear(&sc->geom_list, geom_list_free);
}

void	scene_add_geom(t_scene *sc, t_geom *geom)
{
	t_list	*node;

	node = ft_lstnew(geom);
	ft_lstadd_back(&sc->geom_list, node);
}
