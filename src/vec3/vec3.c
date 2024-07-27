/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:16:19 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 18:38:48 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vec3.h"

void	vec3_init(t_vec3 *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void	vec3_print(t_vec3 *v, char *titel)
{
	if (!v)
		return ;
	printf(MAGENTA"  %s: { ", titel);
	printf(BLACK"%f, %f, %f "MAGENTA"}\n"RESET, v->x, v->y, v->z);
}

void	vec3_copy(t_vec3 *v, t_vec3 *dest)
{
	dest->x = v->x;
	dest->y = v->y;
	dest->z = v->z;
}

void	vec3_invert(t_vec3 *v)
{
	v->x *= -1.0;
	v->y *= -1.0;
	v->z *= -1.0;
}
