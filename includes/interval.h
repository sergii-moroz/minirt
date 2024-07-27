/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:11:30 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/11 09:56:27 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERVAL_H
# define INTERVAL_H

# include <stdio.h>
# include "common.h"

typedef struct s_interval
{
	double	min;
	double	max;
	int		(*surrounds)(struct s_interval *, double);
	int		(*contains)(struct s_interval *, double);
	void	(*print)(struct s_interval *);
	void	(*create)(struct s_interval *, double, double);
}			t_interval;

void	ray_interval_bind(t_interval *interval);

#endif
