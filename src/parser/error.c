/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:41:13 by fcottet           #+#    #+#             */
/*   Updated: 2019/05/13 15:51:27 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		is_valid_scene(char **file)
{
	int	i;
	int	count[5];

	i = 0;
	ft_bzero(count, 20);
	while (file[i])
	{
		if (!ft_strcmp(file[i], "camera"))
			count[0] = 1;
		else if (!ft_strcmp(file[i], "objects"))
			count[1] = 1;
		else if (!ft_strcmp(file[i], "quadric")
				|| !ft_strcmp(file[i], "plane")
				|| !ft_strcmp(file[i], "tore"))
			count[2] = 1;
		else if (!ft_strcmp(file[i], "lights"))
			count[3] = 1;
		else if (!ft_strcmp(file[i], "light"))
			count[4] = 1;
		i++;
	}
	return (count[0] && count[1] && count[2] && count[3] && count[4]) ? 1 : 0;
}

void	ft_usage(void)
{
	ft_putendl("usage: rt file_name");
	exit(0);
}

void	error_file(void)
{
	ft_putendl("Bad config file");
	exit(0);
}
