/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:10:40 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 18:51:02 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/interval.h"

static int	surrounds(t_interval *interval, double x)
{
	return (x > interval->min && x < interval->max);
}

static int	contains(t_interval *interval, double x)
{
	return (x >= interval->min && x <= interval->max);
}

static void	print(t_interval *interval)
{
	printf(YELLOW"RAY_INTERVAL: {\n");
	printf(MAGENTA"  min: "BLACK"%f\n", interval->min);
	printf(MAGENTA"  max: "BLACK"%f\n", interval->max);
	printf(YELLOW"}\n"RESET);
}

static void	create(t_interval *interval, double min, double max)
{
	interval->min = min;
	interval->max = max;
}

void	ray_interval_bind(t_interval *interval)
{
	interval->contains = contains;
	interval->surrounds = surrounds;
	interval->print = print;
	interval->create = create;
}
