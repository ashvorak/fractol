/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:40:03 by oshvorak          #+#    #+#             */
/*   Updated: 2018/07/28 17:07:12 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <pthread.h>
# include "../lib/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/inc/ft_printf.h"
# include "../minilibx_macos/mlx.h"

# define WIN 1000
# define THEAT_NUM 8
# define SQR(x) (x*x)
# define ABS(x) (((x) < 0 ) ? -(x) : (x))

enum			e_fractol
{
	Fail,
	Mandelbrot,
	Julia,
	Burningship
};

typedef struct	s_proj
{
	int		fractol;
	int		row1;
	int		row2;
	double	re_min;
	double	re_max;
	double	im_min;
	double	im_max;
	double	c_re_j;
	double	c_im_j;
	int		color;
	int		move_julia;
	int		iteration_max;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*win_image;
	int		*pixels;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_proj;

void			display(t_proj *proj);
void			put_pixel(int x, int y, t_proj *proj, int color);

void			fractol(t_proj *proj);

int				exit_x(t_proj *proj);
int				manage_keys(int key, t_proj *proj);
int				manage_mouse(int mousecode, int x, int y, t_proj *proj);
int				manage_mouse_julia(int x, int y, t_proj *proj);

#endif
