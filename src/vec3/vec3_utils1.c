/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:24:53 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 18:31:18 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vec3.h"

double	vec3_length_squared(t_vec3 *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}

double	vec3_length(t_vec3 *v)
{
	return (sqrt(vec3_length_squared(v)));
}

double	vec3_dot(t_vec3 *u, t_vec3	*v)
{
	return (u->x * v->x + u->y * v->y + u->z * v->z);
}

void	vec3_mult_const(t_vec3 *v, double t)
{
	v->x *= t;
	v->y *= t;
	v->z *= t;
}
