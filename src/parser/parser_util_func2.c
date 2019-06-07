/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util_func2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 18:46:26 by fcottet           #+#    #+#             */
/*   Updated: 2019/05/25 14:24:00 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		get_vec(double vec[4], char *line, int f)
{
	int		i;
	char	**split;

	(void)f;
	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (!line[i])
		exit(0);
	if (!(split = ft_strsplit(&(line[i + 1]), ';')) || !is_valid_vector(split))
		error_file();
	i = 0;
	vec[0] = ft_atoi(split[i]);
	vec[1] = ft_atoi(split[i + 1]);
	vec[2] = ft_atoi(split[i + 2]);
	vec[3] = 1.0;
	free_tab(split);
}

void		get_color(double color[4], char *line)
{
	int		i;
	char	**split;

	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (!line[i])
		exit(0);
	if (!(split = ft_strsplit(&(line[i + 1]), ';')) || !is_valid_vector(split))
		error_file();
	i = 0;
	color[2] = ft_atoi(split[i]);
	color[1] = ft_atoi(split[i + 1]);
	color[0] = ft_atoi(split[i + 2]);
	color[0] = color[0] / 255;
	color[1] = color[1] / 255;
	color[2] = color[2] / 255;
	free_tab(split);
}

double		get_value(char *str)
{
	int		i;
	double	result;
	double	decimal;
	int		j;

	i = 0;
	result = 0;
	while (str[i] != ':' && str[i])
		i++;
	j = i;
	if (str[i])
		result = ft_atoi(&(str[i + 1]));
	while (str[i] != '.' && str[i])
		i++;
	if (!str[i])
		return (result);
	decimal = ft_atoi(&(str[i + 1]));
	while (decimal >= 1)
		decimal /= 10;
	result = result + decimal;
	return (str[j + 1] == '-') ? -result : result;
}

int			check_obj_token(char **file, int i, int flag)
{
	if (flag == 1 && ft_strcmp(file[i], "quadric") && ft_strcmp(file[i], "plane")
			&& ft_strcmp(file[i], "tore"))
		return (-1);
	if (flag == 2 && !is_token(file[i], "position")
			&& !is_token(file[i], "rayon")
			&& !is_token(file[i], "albedo")
			&& !is_token(file[i], "height")
			&& !is_token(file[i], "alpha")
			&& !is_token(file[i], "color")
			&& !is_token(file[i], "direction")
			&& !is_token(file[i], "shine")
			&& !is_token(file[i], "specularity") && !is_material(file[i]))
		return (-2);
	return (1);
}

int			check_light_token(char **file, int i, int flag)
{
	if (flag == 1 && ft_strcmp(file[i], "light"))
		return (-1);
	if (flag == 2 && !is_token(file[i], "position")
			&& !is_token(file[i], "color")
			&& !is_token(file[i], "intensity"))
		return (-2);
	return (1);
}
