/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:12:30 by temehenn          #+#    #+#             */
/*   Updated: 2019/06/03 16:26:56 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <float.h>

void	printMatrix(double m[4][4])
{
	int	i;
	int	j;

	i = -1;
	puts("|||||||||||||||||||||");
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			printf("%f ", m[i][j]);
		puts("");
	}
}

void	initRay(double x, double y, t_cam cam, t_ray *ray)
{
	t_ray	r2;

	cam.dir[3] = 1;
	cam.pos[3] = 1;
	initTransform(&cam.t, cam.pos, cam.dir);
	ft_memcpy(r2.ori, cam.pos, sizeof(double) * 4);
	r2.ori[3] = 1;
	r2.dir[3] = 1;
	r2.dir[0] = x - SIZE_W / 2;
	r2.dir[1] = y - SIZE_H / 2;
	r2.dir[2] = -SIZE_W / (2 * tan((60  * PI / 180) / 2));
	invTransformation(&cam.t, ray->dir, r2.dir);
	invTransformation(&cam.t, ray->ori, r2.ori);
	normalize(ray->dir);
}

int		raytrace(t_all *all, t_ray r, t_data *data)
{
	closestObj(all->scene.obj, r, data);;
	if (data->hit != NULL)
	{
		if (data->hit->reflect > 0.0 && data->depth-- > 0)
			raytrace(all, reflection(r, data), data);
		else
			getColor(all, data);
	}
	return (0);
}

void    antiAliasing(t_all *all, double j, double i, double color[4])
{
	double  aa;
	double  sx;
	double  sy;
	double  tmp[4];
	t_ray   r;
	t_data  data;

	sy = i;
	aa = 1.0 / AA;
	initVec(color);
	while (sy < i + 1.0)
	{
		sx = j;
		while (sx < j + 1.0)
		{
			initRay(sx, sy, all->scene.cam, &r);
			initData(&data);
			raytrace(all, r, &data);
			doubleVec(data.color, (1.0 / pow(AA, 2.0)), tmp);
			addVec(color, tmp, color);
			sx += aa;
		}
		sy += aa;
	}
	color[0] *= 255;
	color[1] *= 255;
	color[2] *= 255;
}

void	core(t_all *all)
{
	int			i;
	int			j;
	double		color[4];
	int			dl;
	int			dlMax;

	initVec(color);
	i = -1;
	dlMax = SIZE_H * SIZE_W + SIZE_W;
	while (++i < SIZE_H)
	{
		j = -1;
		while (++j < SIZE_W)
		{
			dl = i * SIZE_W + j;
			if (dl % (dlMax / 100) == 0)
				print_bar('|');
			antiAliasing(all, j, i, color);
			light_pixel(j, i, &all->img, color);
		}
	}
	apply_shader(&all->img);
	mlx_put_image_to_window(all->mlx.p_mlx, all->mlx.p_win,
			all->mlx.p_img, 0, 0);
}
