/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:38:12 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 18:00:02 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

static double	linear2gamma(double x)
{
	if (x <= 0.0)
		return (0.0);
	return (sqrt(x));
}

static double	color_clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

int	create_trgb(double tt, double rr, double gg, double bb)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)(256 * linear2gamma(color_clamp(tt, 0.0, 0.999)));
	r = (int)(256 * linear2gamma(color_clamp(rr, 0.0, 0.999)));
	g = (int)(256 * linear2gamma(color_clamp(gg, 0.0, 0.999)));
	b = (int)(256 * linear2gamma(color_clamp(bb, 0.0, 0.999)));
	return (t << 24 | r << 16 | g << 8 | b);
}
