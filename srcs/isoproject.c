/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isoproject.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 14:12:57 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/06 15:31:52 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*isoproject(int x, int y, int z)
{
	int		pre_x;
	int		pre_y;
	t_point	*p;

	pre_x = x;
	pre_y = y;
	x = (pre_x - pre_y) * cos(0.523599);
	y = ((pre_x + pre_y) * sin(0.523599)) - z;
	p = (t_point*)ft_memalloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	return (p);
}
