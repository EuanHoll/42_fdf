/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawmap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 14:18:17 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/07 16:34:02 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void drawline2(t_point *pos1, t_point *pos2, t_mlx *mlx)
{
	int x;
	int y;
	int dx;
	int dy;

	x = pos1->x;
	dx = pos2->x - pos1->x;
	dy = pos2->y - pos1->y;
	while (x < pos2->x)
	{
		y = pos1->y + dy * (x - pos1->x) / dx;
		plotpoint(x, y, DARK_BLUE, mlx->img_add);
		x++;
	}
}

static void	drawmapx(t_mlx *mlx, int x, int z)
{
	int 	t_x;
	int 	t_y;
	int 	t_z;
	t_point	*pos1;
	t_point	*pos2;

	t_x = mlx->map->transform.x;
	t_y = mlx->map->transform.y;
	t_z = mlx->map->transform.z;
	pos1 = isoproject(t_x + (x * mlx->map->zoom), t_z + (z * mlx->map->zoom), t_y + (mlx->map->map[x][z] * mlx->map->zoom));
	pos2 = isoproject(t_x + (x * mlx->map->zoom) + mlx->map->zoom, t_z + (z * mlx->map->zoom), t_y + (mlx->map->map[x + 1][z] * mlx->map->zoom));
	drawline2(pos1, pos2, mlx);
}

static void	drawmapz(t_mlx *mlx, int x, int z)
{
	int 	t_x;
	int 	t_y;
	int 	t_z;
	t_point	*pos1;
	t_point	*pos2;

	t_x = mlx->map->transform.x;
	t_y = mlx->map->transform.y;
	t_z = mlx->map->transform.z;
	pos1 = isoproject(t_x + (x * mlx->map->zoom), t_z + (z * mlx->map->zoom), t_y + (mlx->map->map[x][z] * mlx->map->zoom));
	pos2 = isoproject(t_x + (x * mlx->map->zoom), t_z + (z * mlx->map->zoom) + mlx->map->zoom, t_y + (mlx->map->map[x][z + 1] * mlx->map->zoom));
	drawline2(pos1, pos2, mlx);
}

void		drawmap(t_map *map, t_mlx *mlx)
{
	int x;
	int z;

	z = 0;
	while (z < map->map_size.y)
	{
	 	x = 0;
	 	while (x < map->map_size.x)
	 	{
	 		if (x != map->map_size.x - 1)
	 			drawmapx(mlx, x, z);
	 		if (z != map->map_size.y - 1)
	 			drawmapz(mlx, x, z);
	 		x++;
	 	}
	 	z++;
	}
}
