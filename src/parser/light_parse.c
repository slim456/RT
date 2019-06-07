/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:55:20 by fcottet           #+#    #+#             */
/*   Updated: 2019/05/15 18:30:29 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_lux	*new_light(void)
{
	t_lux	*new;

	if (!(new = malloc(sizeof(t_lux))))
		return (NULL);
	new->next = NULL;
	initVec(new->color);
	initVec(new->inter);
	initVec(new->pos);
	initVec(new->normal);
	new->lux = 0;
	return (new);
}

void	add_light(t_lux **head, t_lux *new)
{
	t_lux	*tmp;

	if (head && new)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		get_lux(char **file, t_lux *light, int *i)
{
	while (ft_strcmp(file[*i], "}"))
	{
		if (is_token(file[*i], "position"))
			get_vec(light->pos, file[*i], 1);
		else if (is_token(file[*i], "intensity"))
			light->lux = get_value(file[*i]);
		else if (is_token(file[*i], "color"))
			get_color(light->color, file[*i]);
		(*i)++;
	}
	return (1);
}

void	fill_lux(char **file, t_scene *scene, int *i)
{
	t_lux	*new;

	if (!(new = new_light()))
		error_file();
	if (!get_lux(file, new, i))
		error_file();
	if (scene->light == NULL)
		scene->light = new;
	else
		add_light(&(scene->light), new);
}

void	fill_light(char **file, t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	scene->light = NULL;
	while (ft_strcmp(file[i], "lights"))
		i++;
	j = count_elem(&(file[i])) + i;
	while (i < j)
	{
		if (!ft_strcmp(file[i], "light"))
			fill_lux(file, scene, &i);
		i++;
	}
	if (scene->light->lux <= 0)
		error_file();
}
