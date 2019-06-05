/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 15:38:54 by lsmienk        #+#    #+#                */
/*   Updated: 2019/06/05 16:27:03 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	car_check(char *elem)
{
	int i;

	i = 0;
	while (elem[i])
	{
		while (elem[i] >= 0 && elem[i] <= 9)
			i++;
		if (elem[i] == ' ')
			i++;
		else if (!elem[i + 1] && elem[i] != ' ')
			return (1);
		else
			return (-1);
	}
	return (1);
}

int			validate(t_list *lst)
{
	int		size;
	t_list	*elem;

	elem = lst;
	size = ft_strcc((char *)elem->content, ' ');
	while (elem != NULL)
	{
		if (ft_strcc((char *)elem->content, ' ') != size)
			return (-1);
		if (car_check((char *)elem->content) == -1)
			return (-1);
		elem = elem->next;
	}
	return (1);
}
