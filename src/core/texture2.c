/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 20:18:08 by teddy             #+#    #+#             */
/*   Updated: 2019/06/03 12:31:43 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


double  clamp(double u, double min, double max)
{
    if (u > max)
        u = max;
    else if (u < min)
        u = min;
    return (u);
}

void       init_skybox(t_obj *s)
{
    s->rayon = 200000;
    s->ambiant = 0.9;
    s->shine = 0;
    s->p_spec = 0;
}
void    init_perlin(t_obj *s)
{
    s->texture.h = 4000;
    s->texture.w = 4000;
    if (!(s->texture.img = (unsigned char *)malloc(sizeof(char)
        * s->texture.h * 3 * s->texture.w)))
        error_file();
    perlin_text(&s->texture, s->color);
    printVec(s->color);
}