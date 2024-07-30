/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:46:03 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/30 15:59:21 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void	set_light(char *s, t_scene *scene)
{
	char	**groups;

	if (scene->had_error)
		return ;
	groups = ft_split_by_space(s);
	parse_position(*groups, &scene->light.pivot, scene);
	parse_intencity(*(groups + 1), &scene->light.intencity, scene);
	parse_color(*(groups + 2), &scene->light.color, scene);
	ft_cleanup(groups);
	if (!scene->had_error)
		scene->light_count++;
}

static void	error_second_light(char *s)
{
	printf(RED"ERROR:\n"RESET);
	printf(RED"\t|| "YELLOW"line: \""RESET);
	printf(BLACK"%s"YELLOW"\"\n"RESET, s);
	printf(RED"\t||\n\t|| "CYAN"A *.rt file should contain "RESET);
	printf(CYAN"only one light's definition.\n"RESET);
	printf(RED"\t|| "CYAN"The second light was found.\n"RESET);
}

void	parse_light(char *s, t_scene *scene)
{
	int	count;

	if (scene->had_error)
		return ;
	if (scene->light_count)
	{
		scene->had_error = 1;
		error_second_light(s);
		return ;
	}
	count = ft_count_words_by_space(s);
	if (count != 3)
	{
		scene->had_error = 1;
		printf(RED"ERROR:\n"RESET);
		printf(RED"\t|| "YELLOW"line: \""RESET);
		printf(BLACK"%.*s"YELLOW"\"\n"RESET, (int)ft_strlen(s) - 1, s);
		printf(RED"\t||\n\t|| "CYAN"The light's definition should "RESET);
		printf(CYAN"have THREE groups of parameters.\n"RESET);
		printf(RED"\t|| "CYAN"{position} {intencity} {color}\n"RESET);
		printf(RED"\t|| "CYAN"Only "RED"%d"CYAN" were found.\n"RESET, count);
		return ;
	}
	set_light(s, scene);
}
