/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:22:23 by oshvorak          #+#    #+#             */
/*   Updated: 2018/07/22 18:34:39 by oshvorak         ###   ########.fr       */
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
	proj->zx = 2.0;
	proj->zy = 4.0;
	proj->iteration_max = 100;
	proj->mlx_ptr = NULL;
	proj->win_ptr = NULL;
	proj->pixels = NULL;
	proj->bits_per_pixel = 0;
	proj->size_line = 0;
	proj->endian = 0;
	return (proj);
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
	proj->mlx_ptr = mlx_init();
	proj->win_ptr = mlx_new_window(proj->mlx_ptr, WIN_X, WIN_Y, "Fractol");
	proj->win_image = mlx_new_image(proj->mlx_ptr, WIN_X, WIN_Y);
	display(proj);
	mlx_key_hook(proj->win_ptr, manage_keys, proj);
	mlx_mouse_hook(proj->win_ptr, manage_mouse, proj);
	mlx_hook(proj->win_ptr, 17, 1L << 17, exit_x, proj);
	mlx_loop(proj->mlx_ptr);
	return (0);
}

