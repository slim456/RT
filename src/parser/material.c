/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 08:36:53 by temehenn          #+#    #+#             */
/*   Updated: 2019/06/02 14:32:09 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		parseQuartic(char *q)
{
	if (!ft_strcmp(q, "elliptic_cone"))
		return (6);
	else if (!ft_strcmp(q, "elliptic_cylinder"))
		return (7);
	else if (!ft_strcmp(q, "hyperbolic_cylinder"))
		return (8);
	else if (!ft_strcmp(q, "parabolic_cylinder"))
		return (9);
	else if (!ft_strcmp(q, "spheroid"))
		return (10);
	else if (!ft_strcmp(q, "sphere"))
		return (11);
	else if (!ft_strcmp(q, "paraboloid"))
		return (12);
	else if (!ft_strcmp(q, "hyperboloid_one"))
		return (13);
	else if (!ft_strcmp(q, "hyperboloid_two"))
		return (14);
	else if (!ft_strcmp(q, "cone"))
		return (15);
	else if (!ft_strcmp(q, "cylinder"))
		return (16);
	else if (!ft_strcmp(q, "plane"))
		return (17);
	else
		error_file();
	return (0);
}

int		getQuadric(char *q)
{
	char	tmp[50];
	int		i;

	i = 0;
	ft_bzero(tmp, 50 * sizeof(char));
	while (*q && *q != ':')
		q++;
	if (*q)
		q++;
	while (*q && *q != ';')
	{
		tmp[i++]= *q;
		q++;
	}
	if (!ft_strcmp(tmp, "ellipsoid"))
		return (1);
	else if  (!ft_strcmp(tmp, "elliptic_paraboloid"))
		return (2);
	else if (!ft_strcmp(tmp, "hyperbolic_paraboloid"))
		return (3);
	else if (!ft_strcmp(tmp, "elliptic_hyperboloid_one"))
		return (4);
	else if (!ft_strcmp(tmp, "elliptic_hyperboloid_two"))
		return (5);
	return (parseQuartic(tmp));
}

int		get_type_text(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (!line[i + 1])
		error_file();
	if (!ft_strncmp("bmp;", line + i + 1, ft_strlen(&line[i + 1])))
		return (1);
	else if (!ft_strncmp("perlin;", line + i + 1, ft_strlen(&line[i + 1])))
		return (2);
	else if (!ft_strncmp("skybox;", line + i + 1, ft_strlen(&line[i + 1])))
		return (3);
	return (0);
}

t_obj	*get_material(char *line, t_obj *obj)
{
	if (is_token(line, "shine"))
		obj->shine = get_value(line);
	if (is_token(line, "ambiant"))
		obj->ambiant = get_value(line);
	else if (is_token(line, "specularity"))
		obj->p_spec = get_value(line);
	else if (is_token(line, "reflection"))
		obj->reflect = get_value(line);
	else if (is_token(line, "refraction"))
		obj->refract = get_value(line);
	else if (is_token(line, "rayon_tore"))
		obj->R = get_value(line);
	else if (is_token(line, "type"))
		obj->e_quadric = getQuadric(line);
	else if (is_token(line, "path"))
	{
		obj->path = ft_strdup(&line[5]);
		obj->path[ft_strlen(obj->path) - 1] = 0;
	}
	else if (is_token(line, "texture"))
		obj->texture.e_text = get_type_text(line);
	else if (is_token(line, "frequency"))
		obj->texture.freq = get_value(line);
	return (obj);
}

int		is_material(char *line)
{
	if (is_token(line, "reflection")
			|| is_token(line, "refraction")
			|| is_token(line, "rayon_tore")
			|| is_token(line, "type")
			|| is_token(line, "path")
			|| is_token(line, "texture")
			|| is_token(line, "frequency")
			|| is_token(line, "ambiant"))
		return (1);
	return (0);
}
