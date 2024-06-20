/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:38:12 by smoroz            #+#    #+#             */
/*   Updated: 2024/06/05 15:46:50 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xff);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xff);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xff);
}

int	get_b(int trgb)
{
	return (trgb & 0xff);
}
