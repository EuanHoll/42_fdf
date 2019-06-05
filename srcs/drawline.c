/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawline.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 16:03:25 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/05 17:52:14 by ehollidg      ########   odam.nl         */
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

void			drawLine(int x0, int y0, int x1, int y1)
{
		
}
