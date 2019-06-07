/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:52:38 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/13 16:08:52 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		check_obj(char **file, int *line)
{
	int	j;
	int	i;

	i = *line + 1;
	j = count_elem(&(file[i - 1]));
	while (++i < *line + j)
	{
		if (!check_elem(file, &i))
			return (0);
	}
	*line = i;
	return (1);
}

t_obj	*new_obj(char *type)
{
	t_obj	*new;

	if (!(new = malloc(sizeof(t_obj))))
		return (NULL);
	new->next = NULL;
	if (!ft_strcmp(type, "quadric"))
		new->e_type = QUADRIC;
	else if (!ft_strcmp(type, "plane"))
		new->e_type = PLANE;
	else if (!ft_strcmp(type, "tore"))
		new->e_type = TORE;
	else
		new->e_type = 0;
	return (new);
}

void	add_obj(t_obj **head, t_obj *new)
{
	t_obj	*tmp;

	if (head && new)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
