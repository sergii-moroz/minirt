/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:15:05 by olanokhi          #+#    #+#             */
/*   Updated: 2024/07/26 16:13:13 by smoroz           ###   ########.fr       */
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
	if (ft_strncmp(trimed_line, "A ", 2) == 0)
		set_ambient(trimed_line + 2, &scene->ambient);
	if (ft_strncmp(trimed_line, "C ", 2) == 0)
		set_camera(trimed_line + 2, &scene->camera);
	if (ft_strncmp(trimed_line, "L ", 2) == 0)
		set_light(trimed_line + 2, &scene->light);
	if (ft_strncmp(trimed_line, "pl ", 3) == 0)
		set_plane(trimed_line + 3, scene);
	if (ft_strncmp(trimed_line, "sp ", 3) == 0)
		set_sphere(trimed_line + 3, scene);
	if (ft_strncmp(trimed_line, "cy ", 3) == 0)
		set_cylinder(trimed_line + 3, scene);
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
	return (1);
}
