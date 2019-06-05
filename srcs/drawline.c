/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawline.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 16:03:25 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/05 18:28:16 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	fpart(double x)
{
	return (x - floor(x));
}

static double	rfpart(double x)
{
	return (1 - fpart(x));
}

static double	hendpoint(int x0, int y0, double gradient, int steep)
{
	double yend;
	double xgap;
	double xpx11;
	double ypx11;

	yend  = y0 + gradient * (round(x0) - x0);
	xgap = rfpart((double)x0 + 0.5);
	xpx11 = round(x0);
	ypx11 = floor(yend);
	if ()
}

void			drawLine(int x0, int y0, int x1, int y1)
{
	double gradient;
	double intery;
	double xpx11;

	gradient = dlgradient(&x0, &y0, &x1, &y1);
	intery = (y0 + gradient * (round(x0) - x0)) + gradient;
	xpx11 = hendpoint(x0, y0, );
}
