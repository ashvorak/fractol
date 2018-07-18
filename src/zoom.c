/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:16:23 by oshvorak          #+#    #+#             */
/*   Updated: 2018/04/04 13:47:24 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	zoom(t_proj *proj, double scale)
{
	int x;
	int y;

	y = 0;
	while (y < proj->height)
	{
		x = 0;
		while (x < proj->width)
		{
			proj->list[y][x].x *= scale;
			proj->list[y][x].y *= scale;
			proj->list[y][x].z *= scale;
			x++;
		}
		y++;
	}
}
