/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dlgradient.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 17:56:44 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/06 10:29:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	gradloop(int x0, int y0, int x1, int y1)
{
	int dx;
	int dy;
	double gradient;

	dx = x1 - x0;
	dy = y1 - y0;
	gradient = (double)((double)dy / (double)dx);
	if (dx == 0)
		gradient = 1.0;
	return (gradient);
}

double			dlgradient(t_point *p0, t_point *p1, int steep)
{
	if (steep)
		swap(p0, p1);
	if (p0->x > p1->x)
		swap(p0, p1);
	return (gradloop((int)p0->x, (int)p0->y, (int)p1->x, (int)p1->y));
}
