#include "../inc/fractol.h"

static int *get_colors(int max, int color)
{
	int i;
	int *colors;

	i = 0;
	colors = (int*)malloc(sizeof(int) * max);
	while (i < max) 
	{
		colors[i] = color;
		color += 10;
		i++;
	}
	return (colors);
}

static void	iter(t_proj *proj, int row, int col, int *colors)
{
	int iteration;
	double x;
	double y;
	double c_re;
	double c_im;
	double x_new;

	x = 0;
	y = 0;
	c_re = (col - WIN_X/proj->zx)*proj->zy/WIN_X;
	c_im = (row - WIN_Y/proj->zx)*proj->zy/WIN_X;
	iteration = 0;
	while (x*x+y*y <= 4 && iteration < proj->iteration_max)
	{
		x_new = x*x - y*y + c_re;
		y = 2*x*y + c_im;
		x = x_new;
		iteration++;
	}
	(iteration < proj->iteration_max) ? put_pixel(col, row, proj, \
	colors[iteration]) : put_pixel(col, row, proj, 0);
}

static void draw(t_proj *proj, int *colors)
{
	int row;
	int col;

	row = 0;
	while (row < WIN_Y) 
	{
		col = 0;
		while (col < WIN_X) 
		{
			iter(proj, row, col, colors);
			col++;
		}
		row++;
	}
}

void	mandelbrot(t_proj *proj)
{
	int *colors;
	int buf = 14129807;

	colors = get_colors(proj->iteration_max, buf);
	draw(proj, colors);
}
