/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 12:39:44 by lsmienk        #+#    #+#                */
/*   Updated: 2019/06/05 13:34:15 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

t_list        *read_file(int fd);
void		drawinfo(void *mlx_info, void *window, int colour);

#endif