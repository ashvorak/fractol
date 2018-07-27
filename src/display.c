/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:59:59 by oshvorak          #+#    #+#             */
/*   Updated: 2018/07/27 17:21:10 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		display(t_proj *proj)
{
	proj->pixels = (int*)mlx_get_data_addr(proj->win_image, \
	&proj->bits_per_pixel, &proj->size_line, &proj->endian);
	mlx_put_image_to_window(proj->mlx_ptr, proj->win_ptr, \
	proj->win_image, 0, 0);
	if (proj->fractol == Mandelbrot)
		mandelbrot(proj);
	else if (proj->fractol == Julia)
		julia(proj);
	mlx_put_image_to_window(proj->mlx_ptr, proj->win_ptr, \
	proj->win_image, 0, 0);
	mlx_string_put(proj->mlx_ptr, proj->win_ptr, \
	1300, 950, 0xFFFFFF, "MADE BY : OSHVORAK");
}
