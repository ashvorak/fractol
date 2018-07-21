/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:40:03 by oshvorak          #+#    #+#             */
/*   Updated: 2018/07/18 14:01:15 by oshvorak         ###   ########.fr       */
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

# define WIN_X 1000
# define WIN_Y 800
# define SCALE 30

enum			s_fractol
{
	Fail,
	Mandelbrot,
	Julia
};

typedef struct	s_proj
{
	int		fractol;
	double 	x;
	double	y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*win_image;
	int		width;
	int		height;
	int		*pixels;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_proj;

void			display(t_proj *proj);
void			put_pixel(int x, int y, t_proj *proj, int color);

void			mandelbrot(t_proj *proj);
void			julia(t_proj *proj);

#endif
