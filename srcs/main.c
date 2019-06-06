/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 11:42:30 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/06 16:14:20 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		gen(t_map *map)
{
	int i;
	int j;

	map->map_size.x = 150;
	map->map_size.y = 150;
	map->map = (int**)ft_memalloc(sizeof(int*) * 150);
	i = 0;
	while (i < 150)
	{
		map->map[i] = (int*)ft_memalloc(sizeof(int) * 150);
		j = 0;
		while (j < 150)
		{
			if (j % 2 == 0)
				map->map[i][j] = 0;
			else
				map->map[i][j] = 10;
			j++;
		}
		i++;
	}
}

static void 	setup_program(t_mlx *mlx, char *str)
{
	int tmp;

	str--;
	tmp = 0;
	mlx->img = mlx_new_image(mlx->info, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->img_add = mlx_get_data_addr(mlx->img, &tmp, &tmp, &tmp);
	mlx->map = (t_map *)ft_memalloc(sizeof(t_map));
	gen(mlx->map);
	hookcontrols(mlx);
	mlx_loop_hook(mlx->info, fdfloop, (void *)mlx);
}

int		main(int argc, char **argv)
{
	t_mlx mlx;

	if (argc == 2)
	{
		mlx.info = mlx_init();
		mlx.win = mlx_new_window(mlx.info, SCREEN_WIDTH, SCREEN_HEIGHT,
			"The Bestest fTf in the worlds.");
		setup_program(&mlx, argv[1]);
		mlx_loop(mlx.info);
	}
	else
	{
		ft_putendl("Usage : ./fdf [Heightmap File]");
	}
}
