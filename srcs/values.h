/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   values.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 15:07:19 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/05 17:24:04 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUES_H
# define VALUES_H

/* Screen Dimensions */
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define SCREEN_VOL SCREEN_HEIGHT * SCREEN_WIDTH
# define SCREEN_VOL_BYTES SCREEN_VOL * 4

/* Event Codes */
# define CLOSE_EVENT 17
# define KEY_PRESS_EVENT 2
# define NULL_MASK 0

/* Colour Codes */
# define LIGHT_BLUE 0x00ffff
# define DARK_BLUE 0x0000ff
# define LIGHT_GREEN 0x66ff66
# define DARK_GREEN 0x00cc00
# define YELLOW 0xffff00
# define GREY 0x999999
# define DUTCH 0xff6600
# define VELA 0xff0000
# define PYXIS 0xb300b3
# define IMRE_PINK 0xeaa8dc
# define PINK 0xff00bf
# define BLACK 0x000000
# define WHITE 0xffffff
# define LIME 0x00ff00

#endif