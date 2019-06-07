/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transMatrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 10:49:30 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/26 20:17:22 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "transformation.h"

void	translation(t_transform *t, double *pos)
{
	double		tmp[4][4];
	int			i;

	i = -1;
	idMatrix(t->translation);
	idMatrix(t->invTranslation);
	while (++i < 3)
		t->translation[i][3] = pos[i];
	ft_memcpy(tmp, t->transformation, 4 * 4 * sizeof(double));
	multMatrix(t->transformation, tmp, t->translation);
	i = -1;
	while (++i < 3)
		t->invTranslation[i][3] = -pos[i];
	ft_memcpy(tmp, t->invTransformation, 4 * 4 * sizeof(double));
	multMatrix(t->invTransformation, t->invTranslation, tmp);
}


void	initRot(double rx[4][4], double ry[4][4], double rz[4][4], double *rot)
{
	idMatrix(rx);
	idMatrix(ry);
	idMatrix(rz);

	rx[1][1] = cos(rot[0]);
	rx[2][1] = sin(rot[0]);
	rx[1][2] = -sin(rot[0]);
	rx[2][2] = cos(rot[0]);
	ry[0][0] = cos(rot[1]);
	ry[2][0] = -sin(rot[1]);
	ry[0][2] = sin(rot[1]);
	ry[2][2] = cos(rot[1]);
	rz[0][0] = cos(rot[2]);
	rz[1][0] = sin(rot[2]);
	rz[0][1] = -sin(rot[2]);
	rz[1][1] = cos(rot[2]);
}

void	initInvRot(double rx[4][4], double ry[4][4], double rz[4][4], double *rot)
{
	rx[1][1] = cos(-rot[0]);
	rx[2][1] = sin(-rot[0]);
	rx[1][2] = -sin(-rot[0]);
	rx[2][2] = cos(-rot[0]);
	ry[0][0] = cos(-rot[1]);
	ry[2][0] = -sin(-rot[1]);
	ry[0][2] = sin(-rot[1]);
	ry[2][2] = cos(-rot[1]);
	rz[0][0] = cos(-rot[2]);
	rz[1][0] = sin(-rot[2]);
	rz[0][1] = -sin(-rot[2]);
	rz[1][1] = cos(-rot[2]);
}

void	rotation(t_transform *t, double *rot)
{
	double	rx[4][4];
	double	ry[4][4];
	double	rz[4][4];
	double	tmp[4][4];
	double	tmp2[4][4];

	convertRad(rot);
	initRot(rx, ry, rz, rot);
	idMatrix(t->rotation);
	multMatrix(tmp, t->rotation, rz);
	multMatrix(tmp2, tmp, ry);
	multMatrix(t->rotation, tmp2, rx);
	ft_memcpy(tmp, t->transformation, 4 * 4 * sizeof(double));
	multMatrix(t->transformation, tmp, t->rotation);
	initInvRot(rx, ry, rz, rot);
	idMatrix(t->invRotation);
	multMatrix(tmp, t->invRotation, rx);
	multMatrix(tmp2, tmp, ry);
	multMatrix(t->invRotation, tmp2, rz);
	ft_memcpy(tmp, t->invTransformation, 4 * 4 * sizeof(double));
	multMatrix(t->invTransformation, t->invRotation, tmp);
}

void	scale(t_transform *t, double *scale)
{
	double	tmp[4][4];
	int		i;

	i = -1;
	idMatrix(t->scale);
	idMatrix(t->invScale);
	while (++i < 3)
		t->scale[i][i] = scale[i];
	ft_memcpy(tmp, t->transformation, 4 * 4 * sizeof(double));
	multMatrix(t->transformation, tmp, t->scale);
	i = -1;
	while (++i < 3)
		t->invScale[i][i] = 1 / scale[i];
	ft_memcpy(tmp, t->invTransformation, 4 * 4 * sizeof(double));
	multMatrix(t->invTransformation, tmp, t->invScale);
}
