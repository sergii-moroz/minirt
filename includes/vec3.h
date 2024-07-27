/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:15:53 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/27 14:02:03 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>
# include <stdio.h>
# include "common.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

typedef t_vec3	t_point3;
typedef t_vec3	t_color3;

//		vec3.c
void	vec3_init(t_vec3 *v, double x, double y, double z);
void	vec3_print(t_vec3 *v, char *titel);
void	vec3_copy(t_vec3 *v, t_vec3 *dest);
void	vec3_invert(t_vec3 *v);

//		vec3_utils1.c
double	vec3_length_squared(t_vec3 *v);
double	vec3_length(t_vec3 *v);
double	vec3_dot(t_vec3 *u, t_vec3	*v);
void	vec3_mult_const(t_vec3 *v, double t);

//		vec3_utils2.c
void	vec3_add(t_vec3 *u, t_vec3 *v, t_vec3 *dest);
void	vec3_mult(t_vec3 *u, t_vec3 *v, t_vec3 *dest);
void	vec3_substract(t_vec3 *u, t_vec3 *v, t_vec3 *dest);
void	vec3_cross(t_vec3 *u, t_vec3 *v, t_vec3 *dest);
void	vec3_normalize(t_vec3 *v, t_vec3 *dest);

//		vec3_utils3.c
int		vec3_near_zero(t_vec3 *v);
void	vec3_reflect(t_vec3 *v, t_vec3 normal, t_vec3 *dest);

//		vec3_random.c
void	vec3_random(t_vec3 *v);
void	vec3_random_clamped(t_vec3 *v, double min, double max);
void	vec3_random_in_unit_sphere(t_vec3 *v);
void	vec3_random_normalized(t_vec3 *v);
void	vec3_random_on_hemisphere(t_vec3 *v, t_vec3 *normal);

#endif
