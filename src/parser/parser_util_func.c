/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:56:07 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/31 12:41:06 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	count_elem(char **file)
{
	int	bracket;
	int	i;

	i = 1;
	bracket = 0;
	if (!ft_strcmp(file[i], "{"))
		bracket++;
	while (file[++i] && bracket > 0)
	{
		if (!ft_strcmp(file[i], "{"))
			bracket++;
		else if (!ft_strcmp(file[i], "}"))
			bracket--;
	}
	return (bracket == 0 && i > 1) ? i - 1 : -1;
}

int	is_token(char *line, char *token)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (ft_strncmp(line, token, i) || !line[i])
		return (0);
	return (1);
}

int	is_number(char *str)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			point++;
		if (str[i] != '.' && !ft_isdigit(str[i]))
			return (0);
		if (str[i] == '.' && !str[i + 1])
			return (0);
		i++;
	}
	return (point > 1) ? 0 : 1;
}

int	check_var(char *line)
{
	int		i;
	int		j;
	char	**var;

	i = 0;
	j = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (!ft_strncmp(line, "type", i)
		|| !ft_strncmp(line, "path", i)
		|| !ft_strncmp(line, "texture", i))
			return (1);
	if (!(var = ft_strsplit(line + i + 1, ';')))
		return (0);
	while (var[j])
	{
		if (!is_number(var[j]))
		{
			free_tab(var);
			return (0);
		}
		j++;
	}
	free_tab(var);
	if (j > 3)
		return (0);
	return (1);
}

int	count_line(char **file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	return (i);
}
