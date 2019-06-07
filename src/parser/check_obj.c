/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:38:43 by fcottet           #+#    #+#             */
/*   Updated: 2019/05/13 14:45:35 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	check_plane(t_obj *obj)
{
	if (obj->albedo < 0 || obj->albedo > 1)
		return (0);
	if (obj->shine > 1 || obj->shine < 0 || obj->p_spec < 0)
		return (0);
	return (1);
}

int	check_quadric(t_obj *obj)
{
	if (obj->albedo < 0 || obj->albedo > 1)
		return (0);
	if (obj->shine > 1 || obj->shine < 0 || obj->p_spec < 0)
		return (0);
	return (1);
}
