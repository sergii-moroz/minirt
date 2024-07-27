/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:08:58 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/06 14:34:53 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
}				t_ray;

void	ray_set_origin(t_ray *ray, t_point3 *point);
void	ray_set_direction(t_ray *ray, t_vec3 *dir);
t_vec3	ray_at(t_ray *ray, double t);

#endif
