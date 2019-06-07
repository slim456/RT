/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:02:15 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/22 14:58:42 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "libft.h"
# include "get_next_line.h"
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include "scene.h"

int					check_quadric(t_obj *obj);
int					check_elem(char **file, int *line);
int					check_obj(char **file, int *line);
int					is_valid_vector(char **split);
void				free_scene(t_scene *scene);
int					get_obj(char **file, t_obj *obj, int *i);
t_obj				*new_obj(char *type);
int					count_line(char **file);
void				free_tab(char **tab);
int					check_cam(char **file, int *i);
int					check_scene(char **file);
int					check_var(char *line);
int					is_token(char *line, char *token);
int					count_elem(char **file);
void				error_file(void);
void				parse(char **file, t_scene *scene);
void				read_file(char *file_name, t_scene *scene);
void				add_obj(t_obj **head, t_obj *new);
void				get_vec(double vec[4], char *line, int flag);
void				get_color(double color[4], char *line);
void				print_obj(t_obj *obj);
double				get_value(char *str);
int					check_obj_token(char **str, int i, int flag);
void				fill_light(char **file, t_scene *scene);
int					is_valid_scene(char **file);
#endif
