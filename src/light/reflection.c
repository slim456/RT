/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:25:49 by fcottet           #+#    #+#             */
/*   Updated: 2019/05/23 16:25:52 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray   reflection(t_ray r, t_data *data)
{
    t_ray   new;

    doubleVec(data->hit->normal, 2 * dotProduct(data->hit->normal, r.dir), new.dir);
    subVec(r.dir, new.dir, new.dir);
    normalize(new.dir);
    doubleVec(data->hit->normal, E, new.ori);
    addVec(data->hit->point, new.ori, new.ori);
    return (new);
}