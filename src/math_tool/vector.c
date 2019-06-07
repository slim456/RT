/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:51:26 by fcottet           #+#    #+#             */
/*   Updated: 2019/05/25 14:24:04 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	addVec(double a[4], double b[4], double c[4])
{
	c[3] = 1;
	c[0] = a[0] + b[0];
	c[1] = a[1] + b[1];
	c[2] = a[2] + b[2];
}

void	doubleVec(double a[4], double b, double c[4])
{
	c[3] = 1;
	c[0] = a[0] * b;
	c[1] = a[1] * b;
	c[2] = a[2] * b;
}

void	subVec(double a[4], double b[4], double c[4])
{
	c[3] = 1;
	c[0] = a[0] - b[0];
	c[1] = a[1] - b[1];
	c[2] = a[2] - b[2];
}

void	mult_vec(double a[4], double b[4], double c[4])
{
	c[3] = 1;
	c[0] = a[0] * b[0];
	c[1] = a[1] * b[1];
	c[2] = a[2] * b[2];
}

double	squareNorm(double a[4])
{
	double	result;

	a[3] = 1;
	result = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	return (result);
}
