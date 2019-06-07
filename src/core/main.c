/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:41:52 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/27 17:44:04 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	main(int ac, char **av)
{
	t_all		all;

	if (ac != 2 && av[1])
		ft_usage();
	read_file(av[1], &(all.scene));
	all = init_var(all);
	loadObj(all.scene.obj);
	core(&all);
	mlx_key_hook(all.mlx.p_win, event, &all);
	mlx_loop(all.mlx.p_mlx);
	return (0);
}
