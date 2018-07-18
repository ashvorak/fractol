/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:43:10 by oshvorak          #+#    #+#             */
/*   Updated: 2018/04/03 15:44:43 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	centering(t_proj *proj, double dx, double dy)
{
	int x;
	int y;

	y = 0;
	while (y < proj->height)
	{
		x = 0;
		while (x < proj->width)
		{
			proj->list[y][x].x += dx;
			proj->list[y][x].y += dy;
			x++;
		}
		y++;
	}
}
