/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plotpoint.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 16:36:24 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/06 11:41:41 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		plotpoint(int x, int y, int colour, void *img_add)
{
	int *i_img;

	i_img = (int*)img_add;
	if (inbounds(x, y)) //&& i_img[(y * SCREEN_WIDTH) + x] == 0)
		ft_memcpy(&i_img[(y * SCREEN_WIDTH) + x], &colour, 4);
}
