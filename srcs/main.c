/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 11:42:30 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/05 13:12:58 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	void *mlx_info;
	void *window;

	argv--;
	if (argc == 2)
	{
		mlx_info = mlx_init();
		window = mlx_new_window(mlx_info, 1280, 720, "The Bestest fTf in the worlds.");
		drawinfo(mlx_info, window, 0x99ff99);
		mlx_loop(mlx_info);
	}
	else
	{
		ft_putendl("Usage : ./fdf [Heightmap File]");
	}
}
