/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:42:43 by oshvorak          #+#    #+#             */
/*   Updated: 2018/04/20 16:46:14 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	rotate_x(t_proj *proj, double angle)
{
	int		x;
	int		y;
	double	tmp;

	y = 0;
	while (y < proj->height)
	{
		x = 0;
		while (x < proj->width)
		{
			tmp = proj->list[y][x].y;
			proj->list[y][x].y = proj->list[y][x].y \
			* cos(angle) + proj->list[y][x].z * sin(angle);
			proj->list[y][x].z = -tmp * sin(angle) \
			+ proj->list[y][x].z * cos(angle);
			x++;
		}
		y++;
	}
}

static void	rotate_y(t_proj *proj, double angle)
{
	int		x;
	int		y;
	double	tmp;

	y = 0;
	while (y < proj->height)
	{
		x = 0;
		while (x < proj->width)
		{
			tmp = proj->list[y][x].x;
			proj->list[y][x].x = proj->list[y][x].x \
			* cos(angle) + proj->list[y][x].z * sin(angle);
			proj->list[y][x].z = -tmp * sin(angle) \
			+ proj->list[y][x].z * cos(angle);
			x++;
		}
		y++;
	}
}

static void	rotate_z(t_proj *proj, double angle)
{
	int		x;
	int		y;
	double	tmp;

	y = 0;
	while (y < proj->height)
	{
		x = 0;
		while (x < proj->width)
		{
			tmp = proj->list[y][x].x;
			proj->list[y][x].x = proj->list[y][x].x \
			* cos(angle) - proj->list[y][x].y * sin(angle);
			proj->list[y][x].y = tmp * sin(angle) \
			+ proj->list[y][x].y * cos(angle);
			x++;
		}
		y++;
	}
}

void		rotation(t_proj *proj, int key, double angle)
{
	double dx;
	double dy;
	double dxx;
	double dyy;

	dx = (proj->list[0][proj->width - 1].x + proj->list[0][0].x) / 2;
	dy = (proj->list[proj->height - 1][0].y + proj->list[0][0].y) / 2;
	if (key == 6 || key == 14)
		rotate_z(proj, angle);
	else if (key == 1 || key == 13)
		rotate_x(proj, angle);
	else if (key == 0 || key == 2)
		rotate_y(proj, angle);
	dxx = (proj->list[0][proj->width - 1].x + proj->list[0][0].x) / 2;
	dyy = (proj->list[proj->height - 1][0].y + proj->list[0][0].y) / 2;
	centering(proj, dx - dxx, dy - dyy);
}
