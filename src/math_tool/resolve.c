/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 08:45:28 by temehenn          #+#    #+#             */
/*   Updated: 2019/05/26 13:34:26 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#define	TWO_PI		6.283185207179586476925286766560
#define	TWO_PI_3	2.0943951023931954923084
#define TWO_PI_43	4.1887902047863909846168

void	init_polynom(t_polynom *eq)
{
	eq->a4 = 0;
	eq->a3 = 0;
	eq->a2 = 0;
	eq->a1 = 0;
	eq->a0 = 0;
	eq->s1 = DBL_MAX;
	eq->s2 = DBL_MAX;
	eq->s3 = DBL_MAX;
	eq->s4 = DBL_MAX;
	eq->q = 0;
	eq->r = 0;
	eq->s = 0;
	eq->t = 0;
}
int		detect_degree(t_polynom *eq)
{
	if (!(eq->a4) && !(eq->a3) && !(eq->a2) && !(eq->a1))
		return (0);
	else if (!(eq->a4) && !(eq->a3) && !(eq->a2))
		return (1);
	else if (!(eq->a4) && !(eq->a3))
		return (2);
	else if (!(eq->a4))
		return (3);
	else
		return (4);
}

void		resolv2(t_polynom *eq)
{
	double	dis;

	dis = eq->a1 * eq->a1 - (4 * eq->a2 * eq->a0);
	if (dis < 0.0)
		return ;
	eq->s1 = (-eq->a1 + sqrt(dis)) / (2 * eq->a2);
	eq->s2 = (-eq->a1 - sqrt(dis)) / (2 * eq->a2);
}

void		resolv3(t_polynom *eq)
{
	if (eq->a3 != 1.0)
	{
		eq->a2 /= eq->a3;
		eq->a1 /= eq->a3;
		eq->a0 /= eq->a3;
	}
	eq->A2 = eq->a2 * eq->a2;
	eq->q = (eq->A2 - 3.0 * eq->a1) / 9.0;
	eq->r = (eq->a2 * (eq->A2 -4.5 * eq->a1) + 13.5 * eq->a0) / 27.0;
	eq->q3 = eq->q * eq->q * eq->q;
	eq->r2 = eq->r * eq->r;
	eq->d = eq->q3 - eq->r2;
	eq->an = eq->a2 / 3.0;
	if (eq->d >= 0.0)
	{
		eq->d = eq->r / sqrt(eq->q3);
		eq->alpha = acos(eq->d) / 3.0;
		eq->sQ = -2.0 * sqrt(eq->q);
		eq->s1 = eq->sQ * cos(eq->alpha) - eq->an;
		eq->s2 = eq->sQ * cos(eq->alpha + TWO_PI_3) - eq->an;
		eq->s3 = eq->sQ * cos(eq->alpha + TWO_PI_43) - eq->an;
	}
	else
	{
		eq->sQ = pow(sqrt(eq->r2 - eq->q3) + fabs(eq->r), 1.0 / 3.0);
		if (eq->r < 0)
			eq->s1 = (eq->sQ + eq->q / eq->sQ) - eq->an;
		else
			eq->s1 = -(eq->sQ + eq->q / eq->sQ) - eq->an;
	}
}

void	resolv(t_polynom *eq)
{
	int	degree;

	degree = detect_degree(eq);
	if (degree == 1)
		eq->s1 = -eq->a0 / eq->a1;
	else if (degree == 2)
		resolv2(eq);
	else if (degree == 3)
		resolv3(eq);
	else if (degree == 4)
		resolv4(eq);
}

/* int	main()
{
	t_polynom	p;

	init_polynom(&p);
	p.a4 = 1;
	p.a3 = -1;
	p.a2 = 1;
	p.a1 = -2;
	p.a0 = 1;
	resolv(&p);
	printf("s1 = %f s2 = %f s3 = %f s4 = %f\n", p.s1, p.s2, p.s3, p.s4);
	return (0);
} */