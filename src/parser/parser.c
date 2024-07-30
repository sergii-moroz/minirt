/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:15:05 by olanokhi          #+#    #+#             */
/*   Updated: 2024/07/30 15:55:27 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static char	*skip_spaces(char *line)
{
	while (ft_isspace(*line))
		line++;
	return (line);
}

static void	set_scene(char *line, t_scene *scene)
{
	char	*trimed_line;

	trimed_line = skip_spaces(line);
	if (ft_strncmp(trimed_line, "A", 1) == 0 && ft_isspace(*(trimed_line + 1)))
		parse_ambient(trimed_line + 2, scene);
	if (ft_strncmp(trimed_line, "C", 1) == 0 && ft_isspace(*(trimed_line + 1)))
		parse_camera(trimed_line + 2, scene);
	if (ft_strncmp(trimed_line, "L", 1) == 0 && ft_isspace(*(trimed_line + 1)))
		parse_light(trimed_line + 2, scene);
	if (ft_strncmp(trimed_line, "pl", 2) == 0 && ft_isspace(*(trimed_line + 2)))
		parse_plane(trimed_line + 3, scene);
	if (ft_strncmp(trimed_line, "sp", 2) == 0 && ft_isspace(*(trimed_line + 2)))
		parse_sphere(trimed_line + 3, scene);
	if (ft_strncmp(trimed_line, "cy", 2) == 0 && ft_isspace(*(trimed_line + 2)))
		parse_cylinder(trimed_line + 3, scene);
}

static void	scene_has_camera(t_scene *scene)
{
	if (scene->had_error)
		return ;
	if (!scene->camera_count)
	{
		scene->had_error = 1;
		printf(RED"ERROR:\n"RESET);
		printf(RED"\t|| Scene has no camera definiton."RESET);
	}
}

int	is_parse_ok(char *file_name, t_scene *scene)
{
	int		fd;
	char	*line;

	ft_memset(scene, 0, sizeof(t_scene));
	fd = open(file_name, 'r');
	if (fd < 0)
		return (printf(RED"Failed to open the file.\n"RESET), 0);
	line = "start";
	while (line && !scene->had_error)
	{
		line = get_next_line(fd);
		if (line && line[0] != '\n')
		{
			set_scene(line, scene);
			free(line);
		}
		else if (line && line[0] == '\n')
		{
			free(line);
			continue ;
		}
	}
	close(fd);
	scene_has_camera(scene);
	return (!scene->had_error);
}
