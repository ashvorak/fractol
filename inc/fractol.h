/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:40:03 by oshvorak          #+#    #+#             */
/*   Updated: 2018/07/27 17:10:02 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include <stdio.h>
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

enum			s_fractol
{
	Fail,
	Mandelbrot,
	Julia
};

typedef struct	s_proj
{
	int		fractol;
	int		y1;
	int		y2;
	double 	Re_min;
	double	Re_max;
	double	Im_min;
	double	Im_max;
	double	c_re_j;
	double	c_im_j;
	int		move_julia;
	int		*colors;
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

void			mandelbrot(t_proj *proj);
void			julia(t_proj *proj);
int				manage_keys(int key, t_proj *proj);
int				manage_mouse(int mousecode, int x, int y, t_proj *proj);
int				manage_mouse_julia(int x, int y, t_proj *proj);

#endif
