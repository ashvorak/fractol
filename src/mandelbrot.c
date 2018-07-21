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
	int max = 1000;
	int *colors = (int*)malloc(sizeof(int) * max);
	int buf = 14129807;

	for (int i = 0; i < max; i++) {
		colors[i] = buf;
		buf += 10;
	}
	for (int row = 0; row < WIN_Y; row++) {
		for (int col = 0; col < WIN_X; col++) {
			double c_re = (col - WIN_X/2.0)*4.0/WIN_X;
			double c_im = (row - WIN_Y/2.0)*4.0/WIN_X;
			double x = 0, y = 0;
			int iteration = 0;
			while (x*x+y*y <= 4 && iteration < max) {
				double x_new = x*x - y*y + c_re;
				y = 2*x*y + c_im;
				x = x_new;
				iteration++;
			}
			ft_printf("row = %d\n", row);
			if (iteration < max)
				put_pixel(col, row, proj, colors[iteration]);
			else
				put_pixel(col, row, proj, 0);
		}
	}
}
