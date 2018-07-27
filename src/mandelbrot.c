/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:13:48 by oshvorak          #+#    #+#             */
/*   Updated: 2018/07/27 17:50:25 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	*get_colors(int max, int color)
{
	int i;
	int *colors;

	i = 0;
	colors = (int*)malloc(sizeof(int) * max);
	while (i < max)
	{
		colors[i] = color;
		color += 15;
		i++;
	}
	return (colors);
}

static void	iter(t_proj *proj, int row, int col, int iteration)
{
	double	x;
	double	y;
	double	c_re;
	double	c_im;
	double	buf;

	c_re = proj->re_min + col * (proj->re_max - proj->re_min) / (WIN - 1);
	c_im = proj->im_min + row * (proj->im_max - proj->im_min) / (WIN - 1);
	x = c_re;
	y = c_im;
	while (x * x + y * y < 4 && iteration < proj->iteration_max)
	{
		buf = x * x - y * y + c_re;
		y = 2 * x * y + c_im;
		x = buf;
		iteration++;
	}
	(iteration < proj->iteration_max) ? put_pixel(col, row, proj, \
	511723 * iteration) : put_pixel(col, row, proj, 0);
}

static void	*draw(void *p)
{
	int		row;
	int		col;
	int		iteration;
	t_proj	*t;

	t = (t_proj*)p;
	row = t->y1;
	iteration = 0;
	while (row < t->y2)
	{
		col = 0;
		while (col < WIN)
		{
			iter(t, row, col, iteration);
			col++;
		}
		row++;
	}
	return (p);
}

void		mandelbrot(t_proj *proj)
{
	int			i;
	int			buf;
	t_proj		p[THEAT_NUM];
	pthread_t	t[THEAT_NUM];

	buf = 16761035;
	proj->colors = get_colors(proj->iteration_max, buf);
	i = 0;
	while (i < THEAT_NUM)
	{
		ft_memcpy((void*)&p[i], (void*)proj, sizeof(t_proj));
		p[i].y1 = (WIN / THEAT_NUM) * i;
		p[i].y2 = p[i].y1 + (WIN / THEAT_NUM);
		i++;
	}
	i = 0;
	while (i < THEAT_NUM)
	{
		pthread_create(&t[i], NULL, draw, &p[i]);
		i++;
	}
	i = 0;
	while (i < THEAT_NUM)
	{
		pthread_join(t[i], NULL);
		i++;
	}
}
