/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:24:53 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 18:33:54 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vec3.h"

void	vec3_add(t_vec3 *u, t_vec3 *v, t_vec3 *dest)
{
	if (!dest)
	{
		u->x += v->x;
		u->y += v->y;
		u->z += v->z;
		return ;
	}
	dest->x = u->x + v->x;
	dest->y = u->y + v->y;
	dest->z = u->z + v->z;
}

void	vec3_mult(t_vec3 *u, t_vec3 *v, t_vec3 *dest)
{
	if (!dest)
	{
		u->x *= v->x;
		u->y *= v->y;
		u->z *= v->z;
		return ;
	}
	dest->x = u->x * v->x;
	dest->y = u->y * v->y;
	dest->z = u->z * v->z;
}

void	vec3_substract(t_vec3 *u, t_vec3 *v, t_vec3 *dest)
{
	if (!dest)
	{
		u->x -= v->x;
		u->y -= v->y;
		u->z -= v->z;
		return ;
	}
	dest->x = u->x - v->x;
	dest->y = u->y - v->y;
	dest->z = u->z - v->z;
}

void	vec3_cross(t_vec3 *u, t_vec3 *v, t_vec3 *dest)
{
	dest->x = u->y * v->z - u->z * v->y;
	dest->y = u->z * v->x - u->x * v->z;
	dest->z = u->x * v->y - u->y * v->x;
}

void	vec3_normalize(t_vec3 *v, t_vec3 *dest)
{
	double	len;

	if (!dest)
		dest = v;
	len = vec3_length(v);
	if (len != 0 && len != 1.0)
		len = 1.0 / len;
	dest->x = v->x * len;
	dest->y = v->y * len;
	dest->z = v->z * len;
}
