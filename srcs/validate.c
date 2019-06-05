/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 15:38:54 by lsmienk        #+#    #+#                */
/*   Updated: 2019/06/05 15:38:54 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	car_check(char *elem)
{
	int i;

	i = 0;
	while (elem)
	{
		while (elem[i] >= 0 && elem[i] <= 9)
			i++;
		if (elem[i] == ' ')
			i++;
		else
			return (-1);
	}
	return (1);
}

int			validate(t_list *lst)
{
	int		size;
	t_list	*elem;

	elem = lst->content;
	size = ft_strcc((char *)elem, ' ');
	while (elem->next != NULL)
	{
		elem->next = ft_lstnew(NULL, 0);
		if (ft_strcc((char *)elem, ' ') != size)
			return (-1);
		if (car_check((char *)elem) == -1)
			return (-1);
		elem = elem->next;
	}
	return (1);
}
