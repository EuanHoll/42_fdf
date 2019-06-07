/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strgetoc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 13:10:30 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/07 13:11:35 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strgetoc(char *str, char c, size_t i)
{
	size_t j;

	if (!str)
		return (0);
	j = 0;
	while (str[j] && j < i)
		i++;
	return (j);
}
