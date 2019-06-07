/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicMatrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:42:34 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/26 20:24:08 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformation.h"

void	pointMatrix(double *res, double p[4], double m[4][4])
{
	int		i;
	int		j;
	double	y;

	i = -1;
	while (++i < 4)
	{
		y = 0.0;
		j = -1;
		while (++j < 4)
			y += m[i][j] * p[j];
		res[i] = y;
	}
	if (res[3] != 0.0)
	{
		i = -1;
		while (++i < 4)
			res[i] /= res[3];
	}
}

void	multMatrix(double res[4][4], double m1[4][4], double m2[4][4])
{
	int		i;
	int		j;
	int		k;
	double	m;
	double	r[4][4];

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			m = 0;
			while (++k < 4)
				m += m1[i][k] * m2[k][j];
			r[i][j] = m;
		}
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			res[i][j] = r[i][j];
	}
}

void	nullMatrix(double m[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m[i][j] = 0;
	}
}

void	idMatrix(double m[4][4])
{
	int	i;

	i = -1;
	nullMatrix(m);
	while (++i < 4)
		m[i][i] = 1;
}
