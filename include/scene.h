/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:24:07 by temehenn          #+#    #+#             */
/*   Updated: 2019/06/02 13:48:53 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# include "transformation.h"

# define KEY_LEFT		123
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_UP			126

typedef struct 		s_text
{
	enum
	{
		BMP = 1,
		PERLIN = 2,
		SKYBOX = 3
	}				e_text;
	char 			signature[2];
	unsigned char	offset;
	int				w;
	int				h;
	unsigned char	*img;
	int				i;
	int				j;
	unsigned int	freq;
}					t_text;

typedef struct			s_ray
{
	int					inside;
	double				dir[4];
	double				ori[4];
	t_transform			t;
}						t_ray;

typedef struct		s_obj
{
	enum
	{
		QUADRIC = 1,
		PLANE = 2,
		TORE = 3
	}				e_type;
	enum
	{
		ELLIPSOID = 1,
		ELLIPTIC_PARABOLOID = 2,
		HYPERBOLIC_PARABOLOID = 3,
		ELLIPTIC_HYPERBOLOID_ONE = 4,
		ELLIPTIC_HYPERBOLOID_TWO = 5,
		ELLIPTIC_CONE = 6,
		ELLIPTIC_CYLINDER = 7,
		HYPERBOLIC_CYLINDER = 8,
		PARABOLIC_CYLINDER = 9,
		SPHEROID = 10,
		SPHERE = 11,
		PARABOLOID = 12,
		HYPERBOLOID_ONE = 13,
		HYPERBOLOID_TWO = 14,
		CONE = 15,
		CYLINDER = 16
	}				e_quadric;
	t_quadric		q;
	t_text			texture;
	double			ambiant;
	char			*path;
	double			reflect;
	double			refract;
	double			shine;
	double			p_spec;
	double			pos[4];
	double			rayon;
	double			alpha;
	double			R;
	double			albedo;
	double			normal[4];
	double			point[4];
	double			color[4];
	double			dir[4];
	double			num;
	t_transform		t;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_lux
{
	double			color[4];
	double			pos[4];
	double			lux;
	double			normal[4];
	double			inter[4];
	struct s_lux	*next;
}					t_lux;

typedef	struct		s_cam
{
	double		focal;
	t_transform	t;
	double		projSize;
	double		fov;
	double		pos[4];
	double		dir[4];
}					t_cam;

typedef	struct		s_tracer
{
	double			projH;
	double			projW;
	double			scaleX;
	double			scaleY;
}					t_tracer;

typedef struct		s_scene
{
	t_tracer		tracer;
	t_cam			cam;
	t_lux			*light;
	t_obj			*obj;
}					t_scene;

void				init_cam(t_cam *cam);
void				initVec(double vec[4]);
#endif
