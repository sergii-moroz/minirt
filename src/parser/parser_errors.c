/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:22:35 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/30 15:59:09 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	parser_error_float(char *s, t_scene *scene)
{
	scene->had_error = 1;
	printf(RED"ERROR:\n"RESET);
	printf(RED"\t|| "YELLOW"line : \""RESET);
	printf(BLACK"%s"YELLOW"\"\n"RESET, s);
	printf(RED"\t||\n\t|| "CYAN" is not a valid float."RESET);
}

void	parser_error_integer(char *s, t_scene *scene)
{
	scene->had_error = 1;
	printf(RED"ERROR:\n"RESET);
	printf(RED"\t|| "YELLOW"line : \""RESET);
	printf(BLACK"%s"YELLOW"\"\n"RESET, s);
	printf(RED"\t||\n\t|| "CYAN" is not a valid integer."RESET);
}
