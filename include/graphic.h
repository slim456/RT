/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:26:14 by temehenn          #+#    #+#             */
/*   Updated: 2019/06/03 16:17:48 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H
# include <mlx.h>
# include "parser.h"
# define SIZE_W 1280
# define SIZE_H 720
# define ESCAPE 53

typedef struct		s_image
{
	char			*img;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_mlx
{
	void			*p_mlx;
	void			*p_win;
	void			*p_img;
}					t_mlx;

typedef struct		s_all
{
	t_image			img;
	t_mlx			mlx;
	t_scene			scene;
}					t_all;

void				core(t_all *all);
char				*light_pixel(int x, int y, t_image *img, double color[4]);
int					event(int key, t_all *all);
void				ft_usage();
void				quit_all(t_all *all);
t_all				init_var(t_all all);

#endif
