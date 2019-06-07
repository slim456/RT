/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 09:18:20 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/27 12:44:21 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	initQuadric(t_quadric *q)
{
	q->a = 0;
	q->b = 0;
	q->c = 0;
	q->d = 0;
	q->e = 0;
	q->f = 0;
	q->g = 0;
	q->h = 0;
	q->i = 0;
	q->j = 0;
	q->A = 0;
	q->B = 0;
	q->C = 0;
	q->t1 = 0;
	q->t2 = 0;
}

double	minSolution(double a, double b)
{
	if (a < 0)
		return (-1);
	if (b > 0.01)
		return (b);
	else if (a > 0.01)
		return (a);
	else
		return (-1);
}
double	quadricSolver(t_quadric q, t_ray r)
{
	double	delta;

	q.A = q.a * r.dir[0] * r.dir[0] + q.b * r.dir[1] * r.dir[1]
		+ q.c * r.dir[2] * r.dir[2] + q.d * r.dir[0] * r.dir[1]
	   	+ q.e * r.dir[0] * r.dir[2] + q.f * r.dir[1] * r.dir[2];
	q.B = 2 * q.a * r.ori[0] * r.dir[0] + 2 * q.b * r.ori[1] * r.dir[1]
		+ 2 * q.c * r.ori[2] * r.dir[2]
	   	+ q.d * (r.ori[0] * r.dir[1] + r.ori[1] * r.dir[0])
	   	+ q.e * (r.ori[0] * r.dir[2] + r.dir[0] * r.ori[2])
		+ q.f * (r.ori[1] * r.dir[2] + r.dir[1] * r.ori[2])
		+ q.g * r.dir[0] + q.h * r.dir[1] + q.i * r.dir[2];
	q.C = q.a * r.ori[0] * r.ori[0] + q.b * r.ori[1] * r.ori[1]
		+ q.c * r.ori[2] * r.ori[2] + q.d * r.ori[0] * r.ori[1]
		+ q.e * r.ori[0] * r.ori[2] + q.f * r.ori[1] * r.ori[2]
		+ q.g * r.ori[0] + q.h * r.ori[1] + q.i * r.ori[2] + q.j;
	delta = q.B * q.B - 4 * q.A * q.C;
	if (delta < 0)
		return (-1);
	if (!q.A)
		return (-q.C / q.B);
	q.t1 = (-q.B + sqrt(delta)) / ( 2 * q.A);
	q.t2 = (-q.B - sqrt(delta)) / ( 2 * q.A);
	return (minSolution(q.t1, q.t2));
}

void	normalQuadric(double normal[4], double point[4], t_quadric q, t_ray r)
{
	normal[3] = 1;
	normal[0] = 2 * q.a * point[0] + q.d * point[1] + q.e * point[2] + q.g;
	normal[1] = 2 * q.b * point[1] + q.d * point[0] + q.f * point[2] + q.h;
	normal[2] = 2 * q.c * point[2] + q.e * point[0] + q.f * point[1] + q.i;
	if (dotProduct(r.dir, normal) < 0)
		doubleVec(normal, -1, normal);
}
