/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:22:23 by oshvorak          #+#    #+#             */
/*   Updated: 2018/07/28 15:35:36 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void		ft_usage(void)
{
	ft_printf("Usage : ./fractol <name>\n");
	ft_printf("        <name> : Mandelbrot\n");
	ft_printf("               : Julia\n");
	exit(1);
}

static t_proj	*new_proj(int fractol)
{
	t_proj *proj;

	if (!(proj = (t_proj*)malloc(sizeof(t_proj))))
		return (NULL);
	proj->fractol = fractol;
	proj->iteration_max = 50;
	proj->c_re_j = -0.7;
	proj->c_im_j = 0.27015;
	proj->move_julia = 1;
	proj->mlx_ptr = NULL;
	proj->win_ptr = NULL;
	proj->pixels = NULL;
	proj->bits_per_pixel = 0;
	proj->size_line = 0;
	proj->endian = 0;
	return (proj);
}

static void		init(t_proj *p, double re_min, double re_max, double im_min)
{
	p->re_min = re_min;
	p->re_max = re_max;
	p->im_min = im_min;
	p->im_max = p->im_min + (p->re_max - p->re_min);
	if (p->fractol == Mandelbrot)
	{
		p->iteration_max = 50;
		p->color = 511723;
	}	
	else if (p->fractol == Julia)
	{
		p->iteration_max = 300;
		p->color = 16770229;
	}
	else
	{
		p->iteration_max = 100;
		p->color = 511723;
	}		
}

static int		exit_x(void)
{
	exit(0);
}

static int		check_fractol(char *av)
{
	if (!ft_strcmp(av, "Mandelbrot"))
		return (Mandelbrot);
	else if (!ft_strcmp(av, "Julia"))
		return (Julia);
	else if (!ft_strcmp(av, "Burningship"))
		return (Burningship);
	return (Fail);
}

int				main(int ac, char **av)
{
	int			fractol;
	t_proj		*proj;

	fractol = 0;
	if (ac != 2 || !(fractol = check_fractol(av[1])))
		ft_usage();
	proj = new_proj(fractol);
	if (fractol == Mandelbrot)
		init(proj, -2.0, 1.0, -1.6);
	else if (fractol == Julia)
		init(proj, -2.0, 1.9, -2.0);
	else if (fractol == Burningship)
		init(proj, -2.0, 1.9, -2.0);	
	proj->mlx_ptr = mlx_init();
	proj->win_ptr = mlx_new_window(proj->mlx_ptr, WIN, WIN, "Fractol");
	proj->win_image = mlx_new_image(proj->mlx_ptr, WIN, WIN);
	display(proj);
	mlx_key_hook(proj->win_ptr, manage_keys, proj);
	mlx_hook(proj->win_ptr, 6, 1L < 6, manage_mouse_julia, proj);
	mlx_mouse_hook(proj->win_ptr, manage_mouse, proj);
	mlx_hook(proj->win_ptr, 17, 1L << 17, exit_x, proj);
	mlx_loop(proj->mlx_ptr);
	return (0);
}
