/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 11:42:30 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/05 14:55:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void 	setup_program(t_mlx *mlx, char *str)
{
	str--;
	hookcontrols(mlx);
	mlx_loop_hook(mlx->info, fdfloop, mlx);
}

int		main(int argc, char **argv)
{
	t_mlx mlx;

	if (argc == 2)
	{
		mlx.info = mlx_init();
		mlx.win = mlx_new_window(mlx.info, 1280, 720, "The Bestest fTf in the worlds.");
		setup_program(&mlx, argv[1]);
		mlx_loop(mlx.info);
	}
	else
	{
		ft_putendl("Usage : ./fdf [Heightmap File]");
	}
}
