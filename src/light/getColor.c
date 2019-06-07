/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getColor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:30:05 by fcottet           #+#    #+#             */
/*   Updated: 2019/06/03 11:15:01 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	is_valid_shadow(t_obj *obj, t_ray r, t_data *data)
{
	t_obj	*tmp;
	int		ret;
	t_obj	*hit;
	double	dobj;
	
	dobj = 0;
	tmp = obj;
	hit = NULL;
	while (tmp)
	{
		ret = isValid(r, tmp, &dobj);
		if (ret > 0 && data->hit->num != tmp->num)
			hit = tmp;
		tmp = tmp->next;
	}
	if (hit != NULL)
		return (dobj);
	return (0);
}

double	check_shadow(t_obj *obj, t_lux *light, t_data *data)
{
	t_ray	shadow;
	double	dobj;

	doubleVec(data->norm, E, shadow.ori);
	addVec(shadow.ori, data->point, shadow.ori);
	subVec(light->pos, shadow.ori, shadow.dir);
	dobj = is_valid_shadow(obj, shadow, data);
	return (dobj);	
}

void	getColor(t_all *all, t_data *data)
{
	t_lux	*tmp;
	double	l[4];
	double	dl2;
	double	dobj;

	doubleVec(data->hit->point, 1, data->point);
	doubleVec(data->hit->normal, 1, data->norm);
	tmp = all->scene.light;
	while (tmp)
	{
		subVec(data->point, tmp->pos, l);
		dl2 = squareNorm(l);
		dobj = check_shadow(all->scene.obj, tmp, data);
		if (dobj > 0 && (dobj * dobj) < dl2)
			;
		else
		{
			diffuseColor(tmp, data, dl2, tmp->pos);
			addVec(data->color, data->diffuse, data->color);
			specular_light(data, tmp);
			addVec(data->color, data->specular, data->color);
		}
		tmp = tmp->next;
	}
	doubleVec(data->hit->color, data->hit->ambiant, data->ambiant);
	addVec(data->color, data->ambiant, data->color);
}