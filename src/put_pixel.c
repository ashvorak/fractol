/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:03:38 by oshvorak          #+#    #+#             */
/*   Updated: 2018/04/05 14:39:26 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	put_pixel(int x, int y, t_proj *proj, int color)
{
	int i;

	if (x >= proj->size_line / 4 || x < 0 || y < 0 || y >= 1000)
		return ;
	i = (x + (y * (proj->size_line / 4)));
	if (color)
		proj->pixels[i] = color;
	else
		proj->pixels[i] = 16657966;
}

