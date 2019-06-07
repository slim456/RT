/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interQuadric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 09:53:35 by temehenn          #+#    #+#             */
/*   Updated: 2019/06/03 11:27:37 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	interQuadric(t_ray r, t_obj *s)
{
	t_ray		r2;
	double		res;
	double		tmp[4];
	double		tmp2[4];

	invTransformation(&s->t, r2.ori, r.ori);
	pointMatrix(r2.dir, r.dir, s->t.invRotation);
	res = quadricSolver(s->q, r2);
	if (res == -1.0)
		return (0);
	calPoint(r2, tmp, res);
	normalQuadric(tmp2, tmp, s->q, r2);
	normalize(tmp2);
	ft_memcpy(s->normal, tmp2, sizeof(double) * 4);
	get_texture(s);
	// printVec(s->color);
	transformation(&s->t, s->point, tmp);
	pointMatrix(s->normal, tmp2, s->t.rotation);
	normalize(s->normal);
	return (res);
}