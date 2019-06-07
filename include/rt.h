/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:30:31 by fcottet           #+#    #+#             */
/*   Updated: 2019/06/03 14:50:40 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include "graphic.h"
# include <pthread.h>
# define SQ(x) ((x) * (x))
# define E		0.00000001
# define AA		1
# include <stdio.h>
# include <float.h>

typedef struct 			s_noise
{
	int					x_s;
	int					y_s;
	int					i;
	int					j;
	int					g[4];
	double				s;
	double				t;
	double				u;
	double				v;
	double				cx;
	double				cy;
	double				grad[8][2];
}						t_noise;


typedef struct			s_tore
{
	double				tmp;
	double				tmpA;
	double				tmpB;
	double				tmpC;
	double				tmpD;
	double				tmpE;
	double				tmpF;
}						t_tore;

typedef	struct			s_polynom
{
	double				a0;
	double				a1;
	double				a2;
	double				a3;
	double				a4;
	double				s1;
	double				s2;
	double				s3;
	double				s4;
	double				A2;
	double				i;
	double				d;
	double				p;
	double				q;
	double				r;
	double				s;
	double				t;
	double				q1;
	double				q2;
	double				q3;
	double				r2;
	double				sQ;
	double				an;
	double				alpha;
}						t_polynom;

typedef struct			s_data
{
	double				color[4];
	int					depth;
	t_obj				*hit;
	double				d;
	double				point[4];
	double				norm[4];
	double				tmpColor[4];
	double				phong;
	double				ambiant[4];
	double				specular[4];
	double				diffuse[4];
}						t_data;

void       				init_skybox(t_obj *s);
void    				init_perlin(t_obj *s);
void					perlin_text(t_text *tex, double color_obj[4]);
void					get_texture(t_obj *s);
void					load_img(char *image_path, t_text *bmp);
t_ray					reflection(t_ray r, t_data *data);
void					specular_light(t_data *data, t_lux *light);
double					isValid2(t_ray r, t_obj *obj, double *d, t_data *data);
void					calShaPoint(t_ray r, t_obj *hit, double d, double point[4]);
void					clampColor(double c[4]);
double					isValid(t_ray r, t_obj *obj, double *d);
void					closestObj(t_obj *obj, t_ray r, t_data *data);
void					ambiantLight(t_data *data);
void					getColor(t_all *all, t_data *data);
void					calPoint(t_ray r, double point[4], double res);
void					diffuseColor(t_lux *light, t_data *data, double dlight2, double lp[4]);
void					normalQuadric(double normal[4], double point[4], t_quadric q, t_ray r);
void					addVec(double a[4], double b[4], double c[4]);
void					doubleVec(double a[4], double b, double c[4]);
void					subVec(double a[4], double b[4], double c[4]);
void					mult_vec(double a[4], double b[4], double c[4]);
double					squareNorm(double a[4]);
void					initData(t_data *data);
void					print_bar(char c);
void					loadObj(t_obj *obj);
double					interQuadric(t_ray r, t_obj *s);
void					initQuadric(t_quadric *q);
double					quadricSolver(t_quadric q, t_ray r);
void					setVec(double vec[4], double x, double y, double z);
double					dotProduct(double v[4], double u[4]);
void					initVec(double v[4]);
void					init_polynom(t_polynom *p);
double					inter_tore(t_ray ray, t_obj *obj);
void					resolv4(t_polynom *p);
void					resolv3(t_polynom *p);
void					resolv(t_polynom *p);
t_ray					init_ray(int i, int j, t_all *all);
t_obj					*get_material(char *line, t_obj *obj);
int						is_material(char *line);
double					clamp(double a, double min, double max);
double					get_max(double a, double b);
int						check_light_token(char **file, int i, int flag);
int						check_sphere(t_obj *obj);
int						check_cylinder(t_obj *obj);
int						check_plane(t_obj *obj);
int						check_cone(t_obj *obj);
void					normalize(double vec[4]);
void					apply_shader(t_image *img);
#endif
