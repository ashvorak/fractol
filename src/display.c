/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:59:59 by oshvorak          #+#    #+#             */
/*   Updated: 2018/04/05 16:09:30 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	show_menu(t_proj *proj)
{
	mlx_string_put(proj->mlx_ptr, \
	proj->win_ptr, 30, 30, 0xFFFFFF, "ZOOM : +, -");
	mlx_string_put(proj->mlx_ptr, \
	proj->win_ptr, 30, 60, 0xFFFFFF, "MOVE : ARROWS");
	mlx_string_put(proj->mlx_ptr, \
	proj->win_ptr, 30, 90, 0xFFFFFF, "ROTATE (X) : W, S");
	mlx_string_put(proj->mlx_ptr, \
	proj->win_ptr, 30, 120, 0xFFFFFF, "ROTATE (Y) : A, D");
	mlx_string_put(proj->mlx_ptr, \
	proj->win_ptr, 30, 150, 0xFFFFFF, "ROTATE (Z) : Z, E");
	mlx_string_put(proj->mlx_ptr, \
	proj->win_ptr, 30, 180, 0xFFFFFF, "PUT CENTER : C");
	mlx_string_put(proj->mlx_ptr, \
	proj->win_ptr, 30, 210, 0xFFFFFF, "CHANGE COLOR : ");
	mlx_string_put(proj->mlx_ptr, proj->win_ptr, 60, 240, 0xFF0000, "R - RED");
	mlx_string_put(proj->mlx_ptr, \
	proj->win_ptr, 60, 270, 0x00FF00, "G - GREEN");
	mlx_string_put(proj->mlx_ptr, proj->win_ptr, 60, 300, 0x0000FF, "B - BLUE");
	mlx_string_put(proj->mlx_ptr, \
	proj->win_ptr, 60, 330, 0xFFFFFF, "F - WHITE");
	mlx_string_put(proj->mlx_ptr, \
	proj->win_ptr, 30, 360, 0xFFFFFF, "EXIT : ESC");
	mlx_string_put(proj->mlx_ptr, proj->win_ptr,\
	1300, 950, 0xFFFFFF, "MADE BY : OSHVORAK");
}

void		display(t_proj *proj)
{
	int x;
	int y;

	proj->pixels = (int*)mlx_get_data_addr(proj->win_image, \
	&proj->bits_per_pixel, &proj->size_line, &proj->endian);
	y = 0;
	while (y < proj->height)
	{
		x = 0;
		while (x < proj->width)
		{
			if (y + 1 < proj->height)
				line(proj, proj->list[y][x], proj->list[y + 1][x]);
			if (x + 1 < proj->width)
				line(proj, proj->list[y][x], proj->list[y][x + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(proj->mlx_ptr, proj->win_ptr, \
	proj->win_image, 0, 0);
	show_menu(proj);
}
