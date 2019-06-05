/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawinfo.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 12:36:55 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/05 13:13:29 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			drawinfo(void *mlx_info, void *window, int colour)
{
	mlx_string_put(mlx_info, window, 1, 1, colour, "Controls");
	mlx_string_put(mlx_info, window, 1, 20, colour, "Rotate : WASD");
	mlx_string_put(mlx_info, window, 1, 40, colour, "Zoom : Mouse Wheel");
	mlx_string_put(mlx_info, window, 1, 60, colour, "Change Projection : P");
}
