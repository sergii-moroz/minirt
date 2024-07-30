/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:40:02 by smoroz            #+#    #+#             */
/*   Updated: 2024/07/30 15:52:42 by smoroz           ###   ########.fr       */
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
// static void	scene_has_camera(t_scene *scene);

//		parser_plane.c
void	parse_plane(char *s, t_scene *scene);
// static void	set_plane(char *s, t_scene *scene);

//		parser_sphere.c
void	parse_sphere(char *s, t_scene *scene);
// static void	set_sphere(char *s, t_scene *scene);

//		parser_cylinder.c
void	parse_cylinder(char *s, t_scene *scene);
// static void	set_cylinder(char *s, t_scene *scene);
// static void	add_cylinder(t_scene *sc, t_cylinder *cy);
// static void	scene_add_cydisk1(t_scene *sc, t_cylinder *cy);
// static void	scene_add_cydisk2(t_scene *sc, t_cylinder *cy);

//		parser_camera.c
void	parse_camera(char *s, t_scene *scene);
// static void	set_camera(char *s, t_scene *scene);
// static void	parse_fov(char *s, t_scene *scene);
// static void	error_second_camera(char *s);

//		parser_ambient.c
void	parse_ambient(char *s, t_scene *scene);
// static void	set_ambient(char *s, t_scene *scene);

//		parser_light.c
void	parse_light(char *s, t_scene *scene);
// static void	set_light(char *s, t_scene *scene);
// static void	error_second_light(char *s);

//		parser_utils.c
void	*ft_malloc(size_t size, t_scene *sc);
void	parse_position(char *s, t_vec3 *pos, t_scene *scene);
void	parse_double(char *s, double *val, t_scene *scene);
void	parse_integer(char *s, double *val, t_scene *scene);
void	parse_color(char *s, t_color3 *color, t_scene *scene);

//		parser_util2s.c
void	parse_normals(char *s, t_vec3 *n, t_scene *scene);
void	check_normals(char *s, t_vec3 *n, t_scene *scene);
void	parse_intencity(char *s, double *val, t_scene *scene);
void	parse_radius(char *s, double *val, t_scene *scene);
void	parse_height(char *s, double *val, t_scene *scene);

//		split_by_space.c
int		ft_count_words_by_space(char const *s);
char	**ft_split_by_space(char const *s);
// static int	ft_find_word_start(char const *s);
// static int	ft_find_word_end(char const *s);

//		parser_errors.c
void	parser_error_float(char *s, t_scene *scene);
void	parser_error_integer(char *s, t_scene *scene);

#endif
