/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadObj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:34:04 by temehenn          #+#    #+#             */
/*   Updated: 2019/06/03 10:56:37 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_quadric	initQuad(double b, double c, double j, double h)
{
	t_quadric	q;

	initQuadric(&q);
	q.a = 1;
	q.b = b;
	q.c = c;
	q.j = j;
	q.h = h;
	return (q);
}

void		loadQuadric2(t_quadric *q, t_obj *obj, double b, double c)
{
	double	r;

	r = obj->rayon * obj->rayon;
	if (obj->e_quadric == 7)
		*q = initQuad(0, c, -r, 0);
	else if (obj->e_quadric == 8)
		*q = initQuad(0, -c, -r, 0);
	else if (obj->e_quadric == 9)
	{
		*q = initQuad(0, 0, 0, 0);
		q->i = 2;
	}
	else if (obj->e_quadric == 10)
		*q = initQuad(b, 1, -r, 0);
	else if (obj->e_quadric == 11)
		*q = initQuad(1, 1, -r, 0);
	else if (obj->e_quadric == 12)
		*q = initQuad(0, 1, 0, -1);
	else if (obj->e_quadric == 13)
		*q = initQuad(-b, 1, -r, 0);
	else if (obj->e_quadric == 14)
		*q = initQuad(-b, 1, r, 0);
	else if (obj->e_quadric == 15)
		*q = initQuad(-b, 1, 0, 0);
	else if (obj->e_quadric == 16)
		*q = initQuad(0, 1, -r, 0);
}

void	loadQuadric(t_quadric *q, t_obj *obj)
{
	double	b;
	double	c;
	double	r;

	b = obj->alpha;
	c = obj->alpha + 3;
	r = obj->rayon * obj->rayon;
	if (obj->e_quadric == 1)
		*q = initQuad(b, c, -r, 0);
	else if (obj->e_quadric == 2)
		*q = initQuad(0, b, 0, -1);
	else if (obj->e_quadric == 3)
		*q = initQuad(0, -b, 0, -1);
	else if (obj->e_quadric == 4)
		*q = initQuad(-b, c, -r, 0);
	else if (obj->e_quadric == 5)
		*q = initQuad(-b, c, r, 0);
	else if (obj->e_quadric == 6)
		*q = initQuad(b, -c, 0, 0);
	else
		loadQuadric2(q, obj, b, c);
}

void	loadObj(t_obj *obj)
{
	t_obj	*tmp;

	tmp = obj;
	while (tmp)
	{
		if (tmp->texture.e_text == SKYBOX && tmp->e_quadric == SPHERE)
			init_skybox(tmp);
		if ((tmp->texture.e_text == BMP  || tmp->texture.e_text == SKYBOX) && tmp->e_quadric == SPHERE)
			load_img(tmp->path, &tmp->texture);
		else if (tmp->texture.e_text == PERLIN && tmp->e_quadric == SPHERE)
			init_perlin(tmp);
		initTransform(&tmp->t, tmp->pos, tmp->dir);
		loadQuadric(&tmp->q, tmp);
		tmp = tmp->next;
	}
}
