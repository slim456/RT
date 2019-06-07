/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:55:04 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/28 20:42:32 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_cam(char **file, t_scene *scene)
{
	int	i;

	i = 0;
	while (ft_strcmp(file[i], "camera"))
		i++;
	get_vec(scene->cam.pos, file[i + 2], 0);
	get_vec(scene->cam.dir, file[i + 3], 1);
}

void	fill_elem(char **file, t_scene *scene, int *i)
{
	t_obj	*new;

	if (!(new = new_obj(file[*i])))
		error_file();
	if (!get_obj(file, new, i))
		error_file();
	if (scene->obj == NULL)
		scene->obj = new;
	else
		add_obj(&(scene->obj), new);
}

void	fill_obj(char **file, t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	while (ft_strcmp(file[i], "objects"))
		i++;
	scene->obj = NULL;
	j = count_elem(&(file[i])) + i;
	while (i < j)
	{
		if (!ft_strcmp(file[i], "quadric")
				|| !ft_strcmp(file[i], "plane")
				|| !ft_strcmp(file[i], "tore"))
			fill_elem(file, scene, &i);
		i++;
	}
}

void	parse(char **file, t_scene *scene)
{
	int	r;

	if (!(r = check_scene(file)))
		error_file();
	fill_cam(file, scene);
	fill_obj(file, scene);
	fill_light(file, scene);
}
