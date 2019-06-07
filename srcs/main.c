/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 11:42:30 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/07 12:24:32 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static void		gen(t_map *map)
{
	int i;
	int j;

	map->map_size.x = 30;
	map->map_size.y = 30;
	map->map = (int**)ft_memalloc(sizeof(int*) * 30);
	i = 0;
	while (i < 30)
	{
		map->map[i] = (int*)ft_memalloc(sizeof(int) * 30);
		j = 0;
		while (j < 30)
		{
			if (j % 2 == 0)
				map->map[i][j] = 0;
			else
				map->map[i][j] = 10;
			j++;
		}
		i++;
	}
}*/

static void		init_map_settings(t_map *map)
{
	map->zoom = 10;
	map->rotation.x = 0;
	map->rotation.y = 0;
	map->rotation.z = 0;
	map->transform.x = 1;
	map->transform.y = 1;
	map->transform.z = 1;
}

static void		setup_program(t_mlx *mlx, char *str)
{
	int		tmp;
	int		fd;
	t_list	*list;

	tmp = 0;
	fd = open(str, O_RDONLY);
	printf("before reading");
	list = read_file(fd);
	mlx->img = mlx_new_image(mlx->info, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->img_add = mlx_get_data_addr(mlx->img, &tmp, &tmp, &tmp);
	mlx->map = (t_map *)ft_memalloc(sizeof(t_map));
	init_map_settings(mlx->map);
	printf("before converting");
	convert_file(mlx->map, list);
	hookcontrols(mlx);
	mlx_loop_hook(mlx->info, fdfloop, (void *)mlx);
}

int		main(int argc, char **argv)
{
	t_mlx mlx;

	if (argc == 2)
	{
		printf("1 argument");
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
