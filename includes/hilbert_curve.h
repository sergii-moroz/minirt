/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hilbert_curve.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:39:42 by smoroz            #+#    #+#             */
/*   Updated: 2024/06/05 14:03:34 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HILBERT_CURVE_H
# define HILBERT_CURVE_H

typedef struct s_int_point
{
	int	x;
	int	y;
}		t_int_point;

// hilbert_curve.c
t_int_point	hindex2xy(int hindex, int order);

#endif
