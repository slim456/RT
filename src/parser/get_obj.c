/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:43:41 by fcottet           #+#    #+#             */
/*   Updated: 2019/06/02 13:49:15 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_obj(t_obj *obj)
{
	static double	num;

	if (!num)
		num = 0;
	obj->ambiant = 0.2;
	obj->path = 0;
	obj->texture.img = 0;
	obj->texture.i = 0;
	obj->texture.j = 0;
	initVec(obj->pos);
	obj->rayon = 4;
	obj->albedo = 0.5;
	obj->alpha = 0.5;
	obj->shine = 0.5;
	obj->p_spec = 50;
	obj->reflect = 0;
	obj->refract = 1;
	obj->R = 5;
	obj->num = num;
	num ++;
}

int		check_values(t_obj *obj)
{
	int	ret;

	ret = 0;
	if (obj->e_type == QUADRIC)
	{
		ret = check_quadric(obj);
	}
	else if (obj->e_type == PLANE)
		ret = check_plane(obj);
	else if (obj->e_type == TORE)
		ret = 1;
	return (ret) ? 1 : 0;
}

int		get_obj(char **file, t_obj *obj, int *i)
{
	init_obj(obj);
	while (ft_strcmp(file[*i], "}"))
	{
		if (is_token(file[*i], "position"))
			get_vec(obj->pos, file[*i], 0);
		else if (is_token(file[*i], "rayon"))
			obj->rayon = get_value(file[*i]);
		else if (is_token(file[*i], "albedo"))
			obj->albedo = get_value(file[*i]);
		else if (is_token(file[*i], "alpha"))
			obj->alpha = get_value(file[*i]);
		else if (is_token(file[*i], "color"))
			get_color(obj->color, file[*i]);
		else if (is_token(file[*i], "direction"))
			get_vec(obj->dir, file[*i], 1);
		else
			obj = get_material(file[*i], obj);
		(*i)++;
	}
	return (check_values(obj)) ? 1 : 0;
}
