/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closestObj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:10:53 by fcottet           #+#    #+#             */
/*   Updated: 2019/05/28 20:04:00 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	isValid(t_ray r, t_obj *obj, double *d)
{
	double	ret;

	ret = 0;
	if (obj->e_type == QUADRIC && ((ret = interQuadric(r, obj)) > 0)
		&& (ret < *d || *d == 0))
			*d = ret;
	else if (obj->e_type == TORE && ((ret = inter_tore(r, obj)) > 0
				&& (ret < *d || *d == 0)))
		*d = ret;
	else
		return (0);
	return (1);
}

void	closestObj(t_obj *obj, t_ray r, t_data *data)
{
	t_obj	*tmp;
	int		ret;
	double	d;

	d = 0;
	tmp = obj;
	while (tmp)
	{
		ret = isValid(r, tmp, &d);
		if (ret > 0)
			data->hit = tmp;
		tmp = tmp->next;
	}
	if (data->hit != NULL)
		data->d = d;
}
