/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:09:51 by olanokhi          #+#    #+#             */
/*   Updated: 2024/07/26 17:22:00 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include "common.h"
# include "scene.h"
# include "../libft/libft.h"

//		validation.c
int		is_args_valid(int argc, char **argv);
// static void	usage(void);
// static int	is_file_rt(char *file);

//		parser.c
int		is_parse_ok(char *file_name, t_scene *scene);
// static char	*skip_spaces(char *line);
// static void	set_scene(char *line, t_scene *scene);

//		parser_set_geoms.c
void	set_plane(char *line, t_scene *sc);
void	set_sphere(char *line, t_scene *sc);

//		parser_set_cylinder.c
void	set_cylinder(char *line, t_scene *sc);
// static void	scene_add_cydisk1(t_scene *sc, t_cylinder *cy);
// static void	scene_add_cydisk2(t_scene *sc, t_cylinder *cy);
// static void	add_cylinder(t_scene *sc, t_cylinder *cy);

//		parser_set.c
void	set_light(char *line, t_light *l);
void	set_camera(char *line, t_camera *c);
void	set_ambient(char *line, t_ambient *a);

//		parser_utils.c
void	*ft_malloc(size_t size, t_scene *sc);
int		get_next_digit(char *line, int i);
void	triple_int_handler(char *line, t_color3 *color, int *i);
void	triple_float_handler(char *line, t_vec3 *vec, int *i);
// static int	get_next_char_after_comma(char *line, int i);

#endif
