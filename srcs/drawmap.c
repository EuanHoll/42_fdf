/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawmap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 14:18:17 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/06 16:15:34 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		drawmap(t_map *map, t_mlx *mlx)
{
	int x;
	int z;

	x = 0;
	while (x < map->map_size.x)
	{
		z = 0;
		while (z < map->map_size.y)
		{
			if (x != map->map_size.x - 1 && x + 1 < map->map_size.x)
				drawline(isoproject(x, map->map[x][z], z),
					isoproject((x) + 1, map->map[x + 1][z], z), mlx);
			if (z != map->map_size.y - 1 && z + 1 < map->map_size.y)
				drawline(isoproject(x, map->map[x][z], z),
					isoproject(x, map->map[x][z + 1], (z) + 1), mlx);
			z++;
		}
		x++;
	}
}
