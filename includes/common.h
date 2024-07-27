/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:39:24 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/26 17:58:42 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define RESET		"\033[0m"

// color.c
int		create_trgb(double tt, double rr, double gg, double bb);
// static double	linear2gamma(double x);
// static double	color_clamp(double x, double min, double max);

// error.c
void	error_fatal(char *s);

// random.c
double	random_double(void);
double	random_clamped(double min, double max);

#endif
