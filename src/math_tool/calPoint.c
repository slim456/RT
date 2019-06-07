/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calPoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:22:44 by fcottet           #+#    #+#             */
/*   Updated: 2019/05/22 22:22:37 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	calPoint(t_ray r, double point[4], double d)
{
	point[3] = 1.0;
	point[0] = r.dir[0] * d + r.ori[0];
	point[1] = r.dir[1] * d + r.ori[1];
	point[2] = r.dir[2] * d + r.ori[2];
}
