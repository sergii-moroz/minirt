/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:46:03 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/30 15:55:05 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void	set_ambient(char *s, t_scene *scene)
{
	char	**groups;

	if (scene->had_error)
		return ;
	groups = ft_split_by_space(s);
	parse_intencity(*groups, &scene->ambient.intencity, scene);
	parse_color(*(groups + 1), &scene->ambient.color, scene);
	ft_cleanup(groups);
	if (!scene->had_error)
		scene->ambient_count++;
}

static void	error_second_ambient(char *s)
{
	printf(RED"ERROR:\n"RESET);
	printf(RED"\t|| "YELLOW"line: \""RESET);
	printf(BLACK"%s"YELLOW"\"\n"RESET, s);
	printf(RED"\t||\n\t|| "CYAN"A *.rt file should contain "RESET);
	printf(CYAN"only one ambient's definition.\n"RESET);
	printf(RED"\t|| "CYAN"The second ambient was found.\n"RESET);
}

void	parse_ambient(char *s, t_scene *scene)
{
	int	count;

	if (scene->had_error)
		return ;
	if (scene->ambient_count)
	{
		scene->had_error = 1;
		error_second_ambient(s);
		return ;
	}
	count = ft_count_words_by_space(s);
	if (count != 2)
	{
		scene->had_error = 1;
		printf(RED"ERROR:\n"RESET);
		printf(RED"\t|| "YELLOW"line: \""RESET);
		printf(BLACK"%.*s"YELLOW"\"\n"RESET, (int)ft_strlen(s) - 1, s);
		printf(RED"\t||\n\t|| "CYAN"The ambient's definition should "RESET);
		printf(CYAN"have TWO groups of parameters.\n"RESET);
		printf(RED"\t|| "CYAN"{intencity} {color}\n"RESET);
		printf(RED"\t|| "CYAN"Only "RED"%d"CYAN" were found.\n"RESET, count);
		return ;
	}
	set_ambient(s, scene);
}
