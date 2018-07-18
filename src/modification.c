/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:17:45 by oshvorak          #+#    #+#             */
/*   Updated: 2018/04/04 13:36:30 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	modification(t_proj *proj, double dx, double dy, double dz)
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
			proj->list[y][x].z += dz;
			x++;
		}
		y++;
	}
}
