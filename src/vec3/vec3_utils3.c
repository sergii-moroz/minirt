/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:24:53 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 18:26:56 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vec3.h"

int	vec3_near_zero(t_vec3 *v)
{
	double	tol;

	tol = 1.0e-8;
	return (fabs(v->x) < tol && fabs(v->y) < tol && fabs(v->z) < tol);
}

void	vec3_reflect(t_vec3 *v, t_vec3 normal, t_vec3 *dest)
{
	double	dot2;

	dot2 = 2.0 * vec3_dot(v, &normal);
	vec3_mult_const(&normal, dot2);
	vec3_substract(v, &normal, dest);
}
