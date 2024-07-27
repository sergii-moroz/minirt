/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:37:48 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 18:03:13 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

double	random_double(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

double	random_clamped(double min, double max)
{
	return (min + (max - min) * random_double());
}
