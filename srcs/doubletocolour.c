/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doubletocolour.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 10:56:06 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/07 11:41:49 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			doubletocolour(double val,int colour)
{
	int a;
	int b;
	int c;
	long hex;

	a = ((colour >> (8*0)) & 0xff) * val;
	b = ((colour >> (8*1)) & 0xff) * val;
	c = ((colour >> (8*2)) & 0xff) * val;
	hex = (a << 16L);
	hex += b << 8L;
	hex += c;
	return ((int)(hex));
}