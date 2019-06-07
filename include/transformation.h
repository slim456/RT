/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:56:03 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/26 20:02:21 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATION_H
# define TRANSFORMATION_H
# include <math.h>
# define PI		3.141592653589793238462
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_quadric
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		e;
	double		f;
	double		g;
	double		h;
	double		i;
	double		j;
	double		A;
	double		B;
	double		C;
	double		t1;
	double		t2;
	double		t;
}				t_quadric;

typedef struct	s_transform
{
	double		translation[4][4];
	double		rotation[4][4];
	double		scale[4][4];
	double		transformation[4][4];
	double		invTranslation[4][4];
	double		invRotation[4][4];
	double		invScale[4][4];
	double		invTransformation[4][4];
}				t_transform;

void			printVec(double y[4]);
void			convertRad(double *vec);
void			printMatrix(double m[4][4]);
void			initTransform(t_transform *t, double *pos, double *dir);
void			invTransformation(t_transform *t, double res[4], double vec[4]);
void			transformation(t_transform *t, double res[4], double vec[4]);
void			rotation(t_transform *t, double *rotation);
void			translation(t_transform *t, double *m);
void			nullMatrix(double m[4][4]);
void			idMatrix(double m[4][4]);
void			multMatrix(double res[4][4], double m1[4][4], double m2[4][4]);
void			pointMatrix(double *res, double p[4], double m[4][4]);

#endif
