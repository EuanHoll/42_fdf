/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawinfo.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 12:36:55 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/07 12:07:50 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			drawinfo(t_mlx *mlx, int colour)
{
	mlx_string_put(mlx->info, mlx->win, 1, 1, colour, "Controls");
	mlx_string_put(mlx->info, mlx->win, 1, 20, colour, "Rotate : WASDZX");
	mlx_string_put(mlx->info, mlx->win, 1, 40, colour, "Zoom : Mouse Wheel");
	mlx_string_put(mlx->info, mlx->win, 1, 60, colour, "Change Projection : P");
}
