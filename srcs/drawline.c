/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawline.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 16:03:25 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/06 15:15:31 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		loopa(double *xpx, double gradient, double intery, t_mlx *mlx)
{
	double x;
	double end;

	x = xpx[0] + 1;
	end = xpx[1] - 1;
	while (x < end)
	{
		plotpoint((int)round(intery), x,
					doubletocolour(rfpart(intery), PYXIS), mlx->img_add);
		plotpoint((int)round(intery) + 1, x,
					doubletocolour(fpart(intery), PYXIS), mlx->img_add);
		intery = intery + gradient;
		x++;
	}
}

static void		loopb(double *xpx, double gradient, double intery, t_mlx *mlx)
{
	double x;
	double end;

	x = xpx[0] + 1;
	end = xpx[1] - 1;
	while (x < end)
	{
		plotpoint(x, (int)round(intery),
					doubletocolour(rfpart(intery), PYXIS), mlx->img_add);
		plotpoint(x, (int)round(intery) + 1,
					doubletocolour(fpart(intery), PYXIS), mlx->img_add);
		intery = intery + gradient;
		x++;
	}
}

static double	hendpoint(t_point *p0, double gradient, int steep, t_mlx *mlx)
{
	double yend;
	double xgap;
	double xpx11;
	double ypx11;

	yend  = p0->y + gradient * (round(p0->x) - p0->x);
	xgap = rfpart(p0->x + 0.5);
	xpx11 = round(p0->x);
	ypx11 = floor(yend);
	if (steep)
	{
		plotpoint(ypx11, xpx11, rfpart(yend) * xgap, mlx->img_add);
		plotpoint(ypx11 + 1, xpx11, fpart(yend) * xgap, mlx->img_add);
	}
	else
	{
		plotpoint(xpx11, ypx11, rfpart(yend) * xgap, mlx->img_add);
		plotpoint(xpx11, ypx11 + 1, fpart(yend) * xgap, mlx->img_add);
	}
	return (xpx11);
}

static double	hsendpoint(t_point *p1, double gradient, int steep, t_mlx *mlx)
{
	double yend;
	double xgap;
	double xpx12;
	double ypx12;

	xpx12 = round(p1->x);
	yend = p1->y + gradient * (xpx12 - p1->x);
	ypx12 = floor(yend);
	xgap = rfpart(p1->x + 0.5);
	if (steep)
	{
		plotpoint(ypx12, xpx12, rfpart(yend) * xgap, mlx->img_add);
		plotpoint(ypx12 + 1, xpx12, fpart(yend) * xgap, mlx->img_add);
	}
	else
	{
		plotpoint(xpx12, ypx12, rfpart(yend) * xgap, mlx->img_add);
		plotpoint(xpx12, ypx12 + 1, fpart(yend) * xgap, mlx->img_add);
	}
	return (xpx12);
}

void			drawline(t_point *p0, t_point *p1, t_mlx *mlx)
{
	double	gradient;
	double	intery;
	double	xpx11;
	double	xpx12;
	int		steep;

	steep = fabs(p1->y - p0->y) > fabs(p1->x - p0->x);
	gradient = dlgradient(p0, p1, steep);
	intery = (p0->y + gradient * (round(p0->x) - p0->x)) + gradient;
	xpx11 = hendpoint(p0, gradient, steep, mlx);
	xpx12 = hsendpoint(p1, gradient, steep, mlx);
	if (steep)
		loopa((double[]){xpx11, xpx12}, gradient, intery, mlx);
	else
		loopb((double[]){xpx11, xpx12}, gradient, intery, mlx);
}
