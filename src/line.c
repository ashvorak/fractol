/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:03:38 by oshvorak          #+#    #+#             */
/*   Updated: 2018/04/05 14:39:26 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static	void	ft_swaps(t_coor *cor1, t_coor *cor2, int i)
{
	double	buf;

	if (i == 1)
	{
		buf = cor1->x;
		cor1->x = cor1->y;
		cor1->y = buf;
		buf = cor2->x;
		cor2->x = cor2->y;
		cor2->y = buf;
	}
	else
	{
		buf = cor1->x;
		cor1->x = cor2->x;
		cor2->x = buf;
		buf = cor1->y;
		cor1->y = cor2->y;
		cor2->y = buf;
		buf = (double)cor1->color;
		cor1->color = cor2->color;
		cor2->color = (int)buf;
	}
}

static	int		ft_incline(t_coor cor1, t_coor cor2)
{
	return (fabs(cor2.y - cor1.y) > fabs(cor2.x - cor1.x));
}

static	void	put_pixel(int x, int y, t_proj *proj, int color)
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

void			line(t_proj *proj, t_coor cor1, t_coor cor2)
{
	double dx;
	double dy;
	double steep;
	double err;
	double ystep;

	if ((steep = ft_incline(cor1, cor2)))
		ft_swaps(&cor1, &cor2, 1);
	if (cor1.x > cor2.x)
		ft_swaps(&cor1, &cor2, 0);
	dx = cor2.x - cor1.x;
	dy = fabs(cor2.y - cor1.y);
	err = dx / 2;
	ystep = (cor1.y < cor2.y) ? 1 : -1;
	while (cor1.x++ < cor2.x)
	{
		put_pixel(steep ? cor1.y : cor1.x, steep ? \
		cor1.x : cor1.y, proj, cor1.color);
		err -= dy;
		if (err < 0)
		{
			cor1.y += ystep;
			err += dx;
		}
	}
}
