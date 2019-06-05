/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 14:27:10 by lsmienk        #+#    #+#                */
/*   Updated: 2019/06/05 14:27:10 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_size(t_list *lst)
{
	return (ft_strcc((char*) lst->content, ' ') * ft_lstcnt(lst));
}

void		place_in_map(t_list *elem, t_map *grid, int z)
{
	while (x < grid->map_size - 1)
		{
			grid->map[x][z] = ;
		}
}

t_map		convert_file(t_list *lst)
{
	t_map	*grid;
	t_list	*elem;
	int		z;

	grid = (t_map*)ft_memalloc(sizeof(t_map));
	elem = lst->content;
	z = 0;
	grid->map_size = get_size(lst);
	while (lst->next != NULL)
	{
		place_in_map(elem, grid, z);
		elem = elem->next;
		z++;
	}
}
