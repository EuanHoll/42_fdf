/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdfloop.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 14:54:23 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/06 11:43:29 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	buildimg(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			plotpoint(x, y, PYXIS, mlx->img_add);
			x++;
		}
		y++;
	}
}

int			fdfloop(void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	ft_bzero(mlx->img_add, SCREEN_VOL_BYTES);
	buildimg(mlx);
	drawline(&(struct s_point){3, 5}, &(struct s_point){1200, 700}, mlx);
	mlx_put_image_to_window(mlx->info, mlx->win, mlx->img, 0, 0);
	drawinfo(mlx, LIME);
	return (1);
}