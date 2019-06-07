/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transMatrix2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:47:32 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/26 16:55:00 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformation.h"

void	transformation(t_transform *t, double res[4], double vec[4])
{
	int	i;

	i = -1;
	pointMatrix(res, vec, t->transformation);
	if (res[3] != 0.0)
		while (++i < 4)
			res[i] /= res[3];
}

void	invTransformation(t_transform *t, double res[4], double vec[4])
{
	int	i;

	i = -1;
	pointMatrix(res, vec, t->invTransformation);
	if (res[3] != 0.0)
		while (++i < 4)
			res[i] /= res[3];
}

void	normalize(double *p)
{
	double	d;
	int		i;

	i = -1;
	d = 0;
	while (++i < 3)
		d += p[i] * p[i];
	d = sqrt(d);
	i = -1;
	while (++i < 3)
		p[i] /= d;
}

double	dotProduct(double u[4], double v[4])
{
	int		i;
	double	res;

	res = 0;
	i = -1;
	while (++i < 3)
		res += u[i] * v[i];
	return (res);
}
void	convertRad(double *rot)
{
	rot[0] = (rot[0] * PI) / 180.0;
	rot[1] = (rot[1] * PI) / 180.0;
	rot[2] = (rot[2] * PI) / 180.0;
}