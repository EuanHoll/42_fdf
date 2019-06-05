/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 12:39:44 by lsmienk        #+#    #+#                */
/*   Updated: 2019/06/05 14:27:29 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define CLOSE_EVENT 17
# define KEY_PRESS_EVENT 2
# define NULL_MASK 0

# include "libft.h"
# include "mlx.h"
# include "keycodes.h"
# include <stdlib.h>

typedef struct  s_map
{
    int     **map;
    size_t  map_size;
}               t_map;


typedef struct	s_mlx
{
	void *info;
	void *win;
}				t_mlx;

t_list			*read_file(int fd);
void			drawinfo(t_mlx *mlx, int colour);
void			hookcontrols(t_mlx *mlx);
int				closeprogram(void *param);

#endif