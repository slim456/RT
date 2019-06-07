/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:22:17 by fcottet           #+#    #+#             */
/*   Updated: 2019/04/27 16:23:32 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	is_valid_vector(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	if (count != 3)
		return (0);
	return (1);
}
