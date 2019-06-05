/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hookcontrols.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 13:44:15 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/05 14:25:57 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	keycontroller(int key, void *param)
{
	if (key == ESC)
		closeprogram(param);
	return (0);
}

void		hookcontrols(t_mlx *mlx)
{
	mlx_hook(mlx->win, KEY_PRESS_EVENT, NULL_MASK,keycontroller, (void*)mlx);
	mlx_hook(mlx->win, CLOSE_EVENT, NULL_MASK, closeprogram, NULL);
}
