/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawmap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 14:18:17 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/07 12:23:50 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawmapa(t_mlx *mlx, int x, int z)
{
	int t_x;
	int t_y;
	int t_z;

	t_x = mlx->map->transform.x;
	t_y = mlx->map->transform.y;
	t_z = mlx->map->transform.z;
	drawline(isoproject(t_x + (x * mlx->map->zoom),
		t_z -(z * mlx->map->zoom), mlx->map->map[x][z] + t_y),
		isoproject(t_x +((x* mlx->map->zoom) + mlx->map->zoom),
		t_z -(z* mlx->map->zoom), mlx->map->map[x + 1][z] + t_y), mlx);
}

static void	drawmapb(t_mlx *mlx, int x, int z)
{
	int t_x;
	int t_y;
	int t_z;

	t_x = mlx->map->transform.x;
	t_y = mlx->map->transform.y;
	t_z = mlx->map->transform.z;
	drawline(isoproject(t_x + (x* mlx->map->zoom),
		t_z -(z* mlx->map->zoom), mlx->map->map[x][z] + t_y),
		isoproject(t_x +(x* mlx->map->zoom),
		t_z -((z* mlx->map->zoom) + mlx->map->zoom),
		mlx->map->map[x][z + 1] + t_y), mlx);
}

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
			if (x != map->map_size.x - 1)
				drawmapa(mlx, x, z);
			if (z != map->map_size.y - 1)
				drawmapb(mlx, x, z);
			z++;
		}
		x++;
	}
}
