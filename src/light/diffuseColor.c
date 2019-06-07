/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuseColor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:28:43 by fcottet           #+#    #+#             */
/*   Updated: 2019/06/03 11:09:27 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	specular_light(t_data *data, t_lux *light)
{
	double	dirlight[4];
	double	vec[4];
	double	reflect[4];
	double	i;

	subVec(data->point, light->pos, dirlight);
	normalize(dirlight);
	doubleVec(data->norm, 2 * dotProduct(data->norm, dirlight), vec);
	subVec(data->point, light->pos, dirlight);
	subVec(dirlight, vec, reflect);
	normalize(reflect);
	normalize(vec);
	i = data->hit->shine * pow(dotProduct(reflect, vec), data->hit->p_spec);
	if (i > 1)
		i = 1;
	if (i < 0)
		i = 0;
	doubleVec(light->color, i, data->specular);
}

void	clamp_color(double vec[4])
{
	vec[0] = vec[0] > 1 ? 1 : vec[0];
	vec[0] = vec[0] < 0 ? 0 : vec[0];
	vec[1] = vec[1] > 1 ? 1 : vec[1];
	vec[1] = vec[1] < 0 ? 0 : vec[1];
	vec[2] = vec[2] > 1 ? 1 : vec[2];
	vec[2] = vec[2] < 0 ? 0 : vec[2];
}

void	printVec(double yolo[4])
{
	printf("x = %.10f, y = %.10f, z = %.10f, h = %.10f\n", yolo[0], yolo[1], yolo[2], yolo[3]);
}

void	diffuseColor(t_lux *light, t_data *data, double dlight2, double lp[4])
{
	double	dirLight[4];
	double	color[4];

	data->phong = 0;
	initVec(data->diffuse);
	subVec(data->point, lp, dirLight);
	normalize(dirLight);
	data->phong = dotProduct(dirLight, data->norm);
	if (data->phong < 0)
		data->phong = 0;
	else if (data->phong > 1)
		data->phong = 1;
	data->phong = (light->lux * data->phong) / dlight2;
	data->phong *= data->hit->albedo;
	mult_vec(light->color, data->hit->color, color);
	doubleVec(color, data->phong, color);
	addVec(data->diffuse, color, data->diffuse);
}
