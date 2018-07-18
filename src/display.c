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

#include "../inc/fractol.h"

static void	show_menu(t_proj *proj)
{
	mlx_string_put(proj->mlx_ptr, \
	proj->win_ptr, 30, 30, 0xFFFFFF, "ZOOM : +, -");
	mlx_string_put(proj->mlx_ptr, \
	proj->win_ptr, 30, 60, 0xFFFFFF, "MOVE : ARROWS");
	mlx_string_put(proj->mlx_ptr, \
	proj->win_ptr, 30, 360, 0xFFFFFF, "EXIT : ESC");
	mlx_string_put(proj->mlx_ptr, proj->win_ptr, \
	1300, 950, 0xFFFFFF, "MADE BY : OSHVORAK");
}

void		display(t_proj *proj)
{
	if (proj->fractol == Mandelbrot)
		mandelbrot(proj);
	else if (proj->fractol == Julia)
		julia(proj);
	show_menu(proj);
}
