/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:13:48 by oshvorak          #+#    #+#             */
/*   Updated: 2018/07/31 15:42:16 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	burningship(t_proj *proj, int row, int col, int i)
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
	while (SQR(x) < 4 && SQR(y) < 4 && i < proj->iteration_max)
	{
		buf = SQR(x) - SQR(y) + c_re;
		y = 2 * ABS(x * y) + c_im;
		x = buf;
		i++;
	}
	if (i < proj->iteration_max)
		(i == 0) ? put_pixel(col, row, proj, proj->color) \
		: put_pixel(col, row, proj, proj->color * i);
	else
		put_pixel(col, row, proj, 0);
}

static void	julia(t_proj *proj, int row, int col, int i)
{
	double	x;
	double	y;
	double	buf;

	x = proj->re_min + col * (proj->re_max - proj->re_min) / (WIN - 1);
	y = proj->im_min + row * (proj->im_max - proj->im_min) / (WIN - 1);
	while (SQR(x) < 4 && SQR(y) < 4 && i < proj->iteration_max)
	{
		buf = SQR(x) - SQR(y) + proj->c_re_j;
		y = 2 * x * y + proj->c_im_j;
		x = buf;
		i++;
	}
	if (i < proj->iteration_max)
		(i == 0) ? put_pixel(col, row, proj, proj->color) \
		: put_pixel(col, row, proj, proj->color * i);
	else
		put_pixel(col, row, proj, 0);
}

static void	mandelbrot(t_proj *proj, int row, int col, int i)
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
	while (SQR(x) < 4 && SQR(y) < 4 && i < proj->iteration_max)
	{
		buf = x * x - y * y + c_re;
		y = 2 * x * y + c_im;
		x = buf;
		i++;
	}
	if (i < proj->iteration_max)
		(i == 0) ? put_pixel(col, row, proj, proj->color) \
		: put_pixel(col, row, proj, proj->color * i);
	else
		put_pixel(col, row, proj, 0);
}

static void	*draw(void *p)
{
	int		i;
	int		row;
	int		col;
	t_proj	*t;

	t = (t_proj*)p;
	row = t->row1;
	i = 0;
	while (row < t->row2)
	{
		col = 0;
		while (col < WIN)
		{
			if (t->fractol == Mandelbrot)
				mandelbrot(t, row, col, i);
			else if (t->fractol == Julia)
				julia(t, row, col, i);
			else if (t->fractol == Burningship)
				burningship(t, row, col, i);
			col++;
		}
		row++;
	}
	return (p);
}

void		fractol(t_proj *proj)
{
	int			i;
	t_proj		p[THEAT_NUM];
	pthread_t	t[THEAT_NUM];

	i = 0;
	while (i < THEAT_NUM)
	{
		ft_memcpy((void*)&p[i], (void*)proj, sizeof(t_proj));
		p[i].row1 = (WIN / THEAT_NUM) * i;
		p[i].row2 = p[i].row1 + (WIN / THEAT_NUM);
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
