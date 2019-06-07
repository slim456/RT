/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:39:26 by fcottet           #+#    #+#             */
/*   Updated: 2019/05/28 20:41:16 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	check_cam(char **file, int *line)
{
	int	j;
	int	i;

	i = *line;
	j = count_elem(&(file[i]));
	if (j != 4 || ft_strcmp(file[i + 1], "{") || ft_strcmp(file[i + 4], "}"))
		return (0);
	if (!is_token(file[i + 2], "position"))
		return (0);
	if (!check_var(file[i + 2]))
		return (0);
	if (!is_token(file[i + 3], "direction"))
		return (0);
	*line += 4;
	return (1);
}

int	check_elem(char **file, int *line)
{
	int	i;

	i = *line;
	if (check_obj_token(file, i, 1) == -1)
		return (0);
	i += 2;
	while (file[i] && ft_strcmp(file[i], "}"))
	{
		if (check_obj_token(file, i, 2) == -2)
			return (0);
		if (!check_var(file[i]))
			return (0);
		i++;
	}
	if (i == *line + 2)
		return (0);
	*line = i;
	return (1);
}

int	check_lux(char **file, int *line)
{
	int	i;

	i = *line;
	if (check_light_token(file, i, 1) == -1)
		return (0);
	i += 2;
	while (file[i] && ft_strcmp(file[i], "}"))
	{
		if (check_light_token(file, i, 2) == -2)
			return (0);
		if (!check_var(file[i]))
			return (0);
		i++;
	}
	if (i == *line + 2)
		return (0);
	*line = i;
	return (1);
}

int	check_lights(char **file, int *line)
{
	int	i;
	int	j;

	i = *line + 1;
	j = count_elem(&(file[i - 1])) + i;
	while (++i < j && ft_strcmp(file[i], "}"))
	{
		if (!check_lux(file, &i))
			return (0);
	}
	*line = i;
	return (1);
}

int	check_scene(char **file)
{
	int	i;
	int	j;
	int	ret;

	i = 2;
	ret = 42;
	if ((j = count_elem(file)) != count_line(file) - 1 ||
			!is_valid_scene(file))
		return (0);
	while (file[i] && i < j && ret != 0)
	{
		if (!ft_strcmp(file[i], "camera"))
			ret = check_cam(file, &i);
		else if (!ft_strcmp(file[i], "objects"))
			ret = check_obj(file, &i);
		else if (!ft_strcmp(file[i], "lights"))
			ret = check_lights(file, &i);
		else if (ft_strcmp(file[i], "}"))
			return (0);
		i++;
	}
	return (ret != 0 && i != 2) ? 1 : 0;
}
