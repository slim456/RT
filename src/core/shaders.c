/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:09:34 by temehenn          #+#    #+#             */
/*   Updated: 2019/06/03 18:19:30 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


void	cartoon_filter(unsigned char *pixel)
{
	int		i;
	int		max;

	i = -1;
	max = 0;
	while (max <= 255)
	{
		i = -1;
		while (++i < 3)
			if (pixel[i] >= max && pixel[i] < max + 25)
				pixel[i] = max;
		max += 25;
	}
}

void	negative_filter(unsigned char *pixel)
{
	int		i;

	i = -1;
	while (++i < 3)
		pixel[i] = 255 - pixel[i];
}

void	sepia_filter(unsigned char *pixel)
{
	double	t[3];

	t[2] = 0.389 * pixel[2] + 0.769 * pixel[1] + 1.189 * pixel[0];
	t[1] = 0.349 * pixel[2] + 0.686 * pixel[1] + 0.168 * pixel[0];
	t[0] = 0.272 * pixel[2] + 0.534 * pixel[1] + 0.131 * pixel[0];
	if (t[2] > 255)
		pixel[2] = 255;
	else
		pixel[2] = (unsigned char)t[2];
	if (t[1] > 255)
		pixel[1] = 255;
	else
		pixel[1] = (unsigned char)t[1];
	if (t[0] > 255)
		pixel[0] = 255;
	else
		pixel[0] = (unsigned char)t[0];
}

void		grey(unsigned char *pixel)
{
	
	double	a;

	
	a = (pixel[0] + pixel[1] + pixel[2]) / 3;
	pixel[0] = a;
	pixel[1] = a;
	pixel[2] = a;
}

void	darkroom(unsigned char *pixel)
{
	double a[3];
	

	a[2] = (pixel[2] * 0.99) + (pixel[1] * 0.99) + (pixel[0] * 0.99);
	a[1] = (pixel[2] + pixel[1] + pixel[0]) / 150;
	a[0] = (pixel[2] + pixel[1] + pixel[0]) / 150;
	//pixel[0] = a[0];
	pixel[1] = a[1];
	pixel[2] = a[2];

	
	 
}

void	blrr(unsigned char *pixel)
{
	double	t[5];
	t[3] = 0.003765 * pixel[5] + 0.015019 * pixel[4] + 0.023792 * pixel[3] + 0.015019 * pixel[2] + 0.003765 * pixel[1];
	//t[2] = 0.389 * pixel[2] + 0.769 * pixel[1] + 1.189 * pixel[0];
	//t[1] = 0.349 * pixel[2] + 0.686 * pixel[1] + 0.168 * pixel[0];
	//t[0] = 0.272 * pixel[2] + 0.534 * pixel[1] + 0.131 * pixel[0];

		pixel[2] = t[3];
}

void	invert(unsigned char *pixel)
{
	pixel[0] = 1.0 - pixel[0];
	pixel[1] = 1.0 - pixel[1];
	pixel[2] = 1.0 - pixel[2];

}



void	gama(unsigned char *pixel)
{
	//double a;
	//pixel[2] = powf(pixel[2], 1.5);
	pixel[1] = powf(pixel[1], 3);
	//pixel[0] = powf(pixel[0], 4.5);

}

void		compute_cyan(unsigned char *pixel)
{
	int		x;
	int		y;
	int		pos;

	y = -1;
	
	
		x = -1;
		
		
			pos = (x * pixel[0]) + (y * pixel[1]);
			pixel[pos] += pixel[pos];
			pixel[pos + 1] += pixel[pos + 1];
		
	
}





void noise(unsigned char *pixel)
{

	double a;
	double t[3];
	

	

	a = (t[2] + pixel[1] + pixel[0] + 128);
	pixel[2] = a;
	pixel[1] = a;
	pixel[0] = a;

}
	






void	apply_shader(t_image *img)
{
	int		x;
	int		y;

	y = -1;
	while (++y < SIZE_H)
	{
		x = -1;
		while (++x < SIZE_W)
			  //cartoon_filter((unsigned char *)&img->img[img->size_line * y + x * 4]);
			  //cartoon_sd((unsigned char *)&img->img[img->size_line * y + x * 4]);
			 //negative_filter((unsigned char *)&img->img[img->size_line * y + x * 4]);
			//compute_cyan((unsigned char *)&img->img[img->size_line * y + x * 4]);
			//noise((unsigned char *)&img->img[img->size_line * y + x * 4]);
			//sepia_filter((unsigned char *)&img->img[img->size_line * y + x * 4]);
			//grey((unsigned char *)&img->img[img->size_line * y + x * 4]);
			//darkroom((unsigned char *)&img->img[img->size_line * y + x * 4]);
			//gama((unsigned char *)&img->img[img->size_line * y + x * 4]);
			//invert((unsigned char *)&img->img[img->size_line * y + x * 4]);
			blrr((unsigned char *)&img->img[img->size_line * y + x * 4]);
	}
}