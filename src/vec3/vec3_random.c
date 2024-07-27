/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:14:20 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 18:15:35 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vec3.h"

void	vec3_random(t_vec3 *v)
{
	v->x = random_double();
	v->y = random_double();
	v->z = random_double();
}

void	vec3_random_clamped(t_vec3 *v, double min, double max)
{
	v->x = random_clamped(min, max);
	v->y = random_clamped(min, max);
	v->z = random_clamped(min, max);
}

void	vec3_random_in_unit_sphere(t_vec3 *v)
{
	while (1)
	{
		vec3_random_clamped(v, -1.0, 1.0);
		if (vec3_length_squared(v) < 1.0)
			return ;
	}
}

void	vec3_random_normalized(t_vec3 *v)
{
	vec3_random_in_unit_sphere(v);
	vec3_normalize(v, NULL);
}

void	vec3_random_on_hemisphere(t_vec3 *v, t_vec3 *normal)
{
	vec3_random_normalized(v);
	if (vec3_dot(v, normal) < 0.0)
		vec3_invert(v);
}
