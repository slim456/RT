/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:45:06 by fcottet           #+#    #+#             */
/*   Updated: 2019/05/10 16:52:03 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	check_color(double color)
{
	if (color > 255)
		color = 255;
	if (color < 0)
		color = 0;
	return (color);
}

char	*light_pixel(int x, int y, t_image *img, double intens[4])
{
	int	pos;

	intens[0] = check_color(intens[0]);
	intens[1] = check_color(intens[1]);
	intens[2] = check_color(intens[2]);
	if ((pos = img->size_line * y + x * 4) < 4 * SIZE_W * SIZE_H && pos > 0
		&& x * 4 < img->size_line && x > 0)
	{
		*(img->img + pos) = (unsigned char)intens[0];
		*(img->img + pos + 1) = (unsigned char)intens[1];
		*(img->img + pos + 2) = (unsigned char)intens[2];
	}
	return (img->img);
}
