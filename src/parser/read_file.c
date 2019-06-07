/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:58:33 by temehenn          #+#    #+#             */
/*   Updated: 2019/04/30 12:52:54 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	**rec_file(char *file_name)
{
	int		fd;
	char	*line;
	int		number;
	char	**file;

	number = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1
		|| ft_strcmp(".rt", file_name + ft_strlen(file_name) - 3) != 0)
	{
		ft_putendl(strerror(errno));
		return (NULL);
	}
	while (get_next_line(fd, &line) > 0)
	{
		number++;
		free(line);
	}
	if (number < 5 || number > 1000000)
		error_file();
	if (!(file = malloc(sizeof(char *) * number + 1)))
		return (NULL);
	close(fd);
	return (file);
}

void	read_file(char *file_name, t_scene *scene)
{
	int		fd;
	char	*line;
	char	**file;
	int		i;

	i = 0;
	if (!(file = rec_file(file_name)))
		exit(0);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		exit(0);
	while (get_next_line(fd, &line) > 0)
	{
		file[i] = ft_strtrim(line);
		free(line);
		i++;
	}
	file[i] = NULL;
	parse(file, scene);
	close(fd);
}
