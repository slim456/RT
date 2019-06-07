/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:37:08 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/30 15:46:05 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	free_obj(t_obj **obj)
{
	t_obj	*tmp;

	if (obj)
	{
		while ((*obj))
		{
			tmp = *obj;
			*obj = (*obj)->next;
			if (tmp->texture.img)
				free(tmp->texture.img);
			free(tmp);
		}
	}
}

void	free_light(t_lux **light)
{
	t_lux	*tmp;

	if (light)
	{
		while ((*light))
		{
			tmp = *light;
			*light = (*light)->next;
			free(tmp);
		}
	}
}

void	free_scene(t_scene *scene)
{
	free_obj(&(scene->obj));
	free_light(&(scene->light));
	scene = NULL;
}
