/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isoproject.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 14:12:57 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/07 16:03:33 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*isoproject(int x, int z, int y)
{
	int		pre_x;
	int		pre_z;
	int		pre_y;
	t_point	*p;

	pre_x = x;
	pre_z = z;
	pre_y = y;
	x = (pre_x + pre_z) * cos(0.523599);
	z = ((pre_x - pre_z) *  sin(0.523599)) - pre_y;
	p = (t_point*)ft_memalloc(sizeof(t_point));
	p->x = x;
	p->y = z;
	return (p);
}
