/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:58:26 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/26 20:21:28 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void        initData(t_data *data)
{
	initVec(data->color);
	data->depth = 30;
	data->hit = NULL;
	data->d = 0;
	initVec(data->point);
	initVec(data->norm);
	initVec(data->diffuse);
	initVec(data->ambiant);
	initVec(data->specular);
}

t_all		init_var(t_all all)
{
	all.mlx.p_mlx = mlx_init();
	all.mlx.p_win = mlx_new_window(all.mlx.p_mlx, SIZE_W, SIZE_H, "rt");
	all.mlx.p_img = mlx_new_image(all.mlx.p_mlx, SIZE_W, SIZE_H);
	all.img.img = mlx_get_data_addr(all.mlx.p_img,
			&(all.img.bits_per_pixel),
			&(all.img.size_line),
			&(all.img.endian));
	return (all);
}

void	initVec(double vec[4])
{
	int	i;

	i = -1;
	while (++i < 3)
		vec[i] = 0;
	vec[3] = 1;
}

void	initTransform(t_transform *t, double pos[4], double dir[4])
{
	idMatrix(t->transformation);
	idMatrix(t->translation);
	idMatrix(t->rotation);
	idMatrix(t->invRotation);
	idMatrix(t->invTranslation);
	idMatrix(t->invTransformation);
	translation(t, pos);
	rotation(t, dir);
}
void	setVec(double vec[4], double x, double y, double z)
{
	vec[0] = x;
	vec[1] = y;
	vec[2] = z;
}
