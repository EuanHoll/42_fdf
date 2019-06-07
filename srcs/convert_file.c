/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 14:27:10 by lsmienk        #+#    #+#                */
/*   Updated: 2019/06/07 17:03:58 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	place_in_map(t_list *elem, t_map *map, int x)
{
	char	**split;
	int		i;
	int		y;

	split = ft_strsplit((char*)(elem->content), ' ');
	y = 0;
	i = 0;
	map->map[x] = (int*)ft_memalloc(sizeof(int) * map->map_size.y);
	while (y < map->map_size.y - 1)
	{
		map->map[x][y] = ft_atoi(split[i]);
		i++;
		y++;
	}
}

t_map		*convert_file(t_map *map, t_list *lst)
{
	t_list	*elem;
	int		x;

	map->map_size.x = ft_lstcnt(lst);
	map->map_size.y = ft_strcc((char*)lst->content, ' ');
	map->map = (int**)ft_memalloc(sizeof(int*) * map->map_size.x);
	elem = lst;
	x = 0;
	while (x < map->map_size.x)
	{
		place_in_map(elem, map, x);
		elem = elem->next;
		x++;
	}
	return (map);
}
