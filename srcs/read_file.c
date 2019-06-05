/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 12:36:55 by lsmienk        #+#    #+#                */
/*   Updated: 2019/06/05 13:29:57 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		free_content(void *content, size_t content_size)
{
	ft_memdel(&content);
}

static t_list	*free_return(t_list *map)
{
	ft_lstdel(map, free_content);
	return (NULL);
}

t_list		*read_file(int fd)
{
	t_list	*map;
	t_list	*elm;
	char	*s1;
	size_t	y;

	y = 0;
	map = ft_lstnew(NULL, 0);
	if (!map)
		return (NULL);
	elm = map;
	while (ft_get_next_line(fd, s1))
	{
		if (y > 0)
		{
			elm->next = ft_lstnew(NULL, 0);
			if (!elm)
				return (free_return(map));
			elm = elm->next;
		}
		elm->content = s1;
		elm->content_size = sizeof(s1);
		y++;
	}
	return (map);
}