/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 11:42:30 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/05 11:51:17 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int		main(int argc, char **argv)
{
	void *mlx_val;
	void *win_ptr;

	argc--;
	argv--;
	mlx_val = mlx_init();
	win_ptr = mlx_new_window(mlx_val, 500, 500, "The Bestest fTf in the worlds.");
	mlx_loop(mlx_val);
}
