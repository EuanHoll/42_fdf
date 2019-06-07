/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hookcontrols.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 13:44:15 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/07 14:40:04 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	keycontroller(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	if (key == KEY_ESC)
		closeprogram(param);
	else if (key == KEY_A)
		mlx->map->transform.x -= 6;
	else if (key == KEY_D)
		mlx->map->transform.x += 6;
	else if (key == KEY_W)
		mlx->map->transform.z += 6;
	else if (key == KEY_S)
		mlx->map->transform.z -= 6;
	else if (key == KEY_Z)
		mlx->map->transform.y += 6;
	else if (key == KEY_X)
		mlx->map->transform.y -= 6;
	return (0);
}

static int	mouse_zoom(int button, int x, int y, void *param)
{
	t_mlx *mlx;

	x -=y;
	mlx = (t_mlx*)param;
	if (button == 4)
		mlx->map->zoom *= 1.1;
	else if (button == 5)
		mlx->map->zoom /= 1.1;
	return (0);
}

void		hookcontrols(t_mlx *mlx)
{
	mlx_hook(mlx->win, KEY_PRESS_EVENT, NULL_MASK,keycontroller, (void*)mlx);
	mlx_hook(mlx->win, CLOSE_EVENT, NULL_MASK, closeprogram, NULL);
	mlx_mouse_hook(mlx->win, mouse_zoom, mlx);
}
