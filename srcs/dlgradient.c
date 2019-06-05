/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dlgradient.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 17:56:44 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/05 18:09:07 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	gradloop(int x0, int y0, int x1, int y1)
{
	int dx;
	int dy;
	float gradient;

	dx = x1 - x0;
	dy = y1 - y0;
	gradient = (float)((float)dy / (float)dx);
	if (dx == 0)
		gradient = 1.0;
	return (gradient);
}

float			dlgradient(int x0, int y0, int x1, int y1)
{
	if (abs(y1 - y0) > abs(x1 - x0))
	{
		swap(&x0, &x1);
		swap(&y0, &y1);
	}
	if (x0 > x1)
	{
		swap(&x0, &x1);
        swap(&y0, &y1);
	}
	return (dlgradient(x0, y0, x1, y1));
}
