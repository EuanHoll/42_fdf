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

static void	place_in_map(t_list *elem, t_map *map, int z)
{
	char	*line;
	int		i;
	int		x;

	line = (char*)(elem->content);
	x = 0;
	i = 0;
	map->map[z] = (int*)ft_memalloc(sizeof(int) * map->map_size.x);
	while (x < map->map_size.x)
	{
		map->map[z][x] = ft_atoi(&line[i]);
		x++;
	}
}

t_map		*convert_file(t_map *map, t_list *lst)
{
	t_list	*elem;
	int		z;

	map->map_size.x = ft_strcc((char*)lst->content, ' ');
	map->map_size.y = ft_lstcnt(lst);
	map->map = (int**)ft_memalloc(sizeof(int*) * map->map_size.y);
	elem = lst->content;
	z = 0;
	while (z < map->map_size.y)
	{
		place_in_map(elem, map, z);
		elem = elem->next;
		z++;
	}
	return (map);
}
