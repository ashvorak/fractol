#include "../inc/fractol.h"
/*
static void draw()
{
	int i;

	i = 0;
	while ()
}
*/
void	mandelbrot(t_proj *proj)
{
	int i;
	int max = 1000;
	int *colors = (int*)malloc(sizeof(int) * max);
	int buf = 14129807;

	i = 0;
	while (i < max) 
	{
		colors[i] = buf;
		buf += 10;
		i++;
	}
	for (int row = 0; row < WIN_Y; row++) {
		for (int col = 0; col < WIN_X; col++) {
			double c_re = (col - WIN_X/proj->zx)*proj->zy/WIN_X;
			double c_im = (row - WIN_Y/proj->zx)*proj->zy/WIN_X;
			double x = 0;
			double y = 0;
			int iteration = 0;
			while (x*x+y*y <= 4 && iteration < proj->iteration_max) {
				double x_new = x*x - y*y + c_re;
				y = 2*x*y + c_im;
				x = x_new;
				iteration++;
			}
			if (iteration < proj->iteration_max)
				put_pixel(col, row, proj, colors[iteration]);
			else
				put_pixel(col, row, proj, 0);
		}
	}
}
