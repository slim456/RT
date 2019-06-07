/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_tore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:48:22 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/27 12:44:05 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	dist(t_polynom p)
{
	double	min;

	min = DBL_MAX;
	if (p.s1 > 0 && p.s1 < min)
		min = p.s1;
	else if (p.s2 > 0 && p.s2 < min)
		min = p.s2;
	else if (p.s3 > 0 && p.s3 < min)
		min = p.s3;
	else if (p.s4 > 0 && p.s4 < min)
		min = p.s4;
	if (min == DBL_MAX)
		return (-1);
	return (min);
}

void	calc_coeff(t_polynom *p, t_ray r2, t_obj *s)
{
	t_tore	t;

	init_polynom(p);
	t.tmpA = r2.dir[0] * r2.dir[0] + r2.dir[1] * r2.dir[1] + r2.dir[2] * r2.dir[2];
	t.tmpB = 2.0 * (r2.dir[0] * r2.ori[0] + r2.dir[1] * r2.ori[1] + r2.dir[2] * r2.ori[2]);
	t.tmpC = r2.ori[0] * r2.ori[0] + r2.ori[1] * r2.ori[1] + r2.ori[2] * r2.ori[2]
		+ s->R * s->R - s->rayon * s->rayon;
	t.tmp = 4.0 * s->R * s->R;
	t.tmpD = t.tmp * (r2.dir[0] * r2.dir[0] + r2.dir[2] * r2.dir[2]);
	t.tmpE = t.tmp * 2 * (r2.dir[0] * r2.ori[0] + r2.dir[2] * r2.ori[2]);
	t.tmpF = t.tmp * (r2.ori[0] * r2.ori[0] + r2.ori[2] * r2.ori[2]);
 	p->a4 = t.tmpA * t.tmpA;
	p->a3 = 2.0 * t.tmpA * t.tmpB;
	p->a2 = 2.0 * t.tmpA * t.tmpC + t.tmpB * t.tmpB - t.tmpD;
  	p->a1 = 2.0 * t.tmpB * t.tmpC - t.tmpE;
  	p->a0 = t.tmpC * t.tmpC - t.tmpF;
}

void	normal_tore(double normal[4], double p[4], t_ray r, t_obj *s)
{
	double	k;

	k = 4 * (p[0] * p[0] + p[1] * p[1] + p[2] * p[2] + s->R * s->R - s->rayon * s->rayon);
	normal[0] = p[0] * k - 8 * s->R * s->R * p[0];
	normal[1] = p[1] * k;
	normal[2] = p[2] * k - 8 * s->R * s->R * p[2];
	normal[3] = 1;
	if (dotProduct(r.dir, normal) < 0)
		doubleVec(normal, -1, normal);
}
double	inter_tore(t_ray r, t_obj *s)
{
	t_polynom	p;
	t_ray		r2;
	double		res;
	double		tmp[4];
	double		tmp2[4];
	
	invTransformation(&s->t, r2.ori, r.ori);
	pointMatrix(r2.dir, r.dir, s->t.invRotation);
	calc_coeff(&p, r2, s);
	resolv(&p);
	res = dist(p);
	if (res == -1)
		return (0);
	calPoint(r2, tmp, res);
	normal_tore(tmp2, tmp, r2, s);
	transformation(&s->t, s->point, tmp);
	transformation(&s->t, s->normal, tmp2);
	normalize(s->normal);
	return (res);
}