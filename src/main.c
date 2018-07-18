/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:22:23 by oshvorak          #+#    #+#             */
/*   Updated: 2018/04/05 15:01:21 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static t_proj	*new_proj(void)
{
	t_proj *proj;

	if (!(proj = (t_proj*)malloc(sizeof(t_proj))))
		return (NULL);
	proj->list = NULL;
	proj->mlx_ptr = NULL;
	proj->win_ptr = NULL;
	proj->width = 0;
	proj->height = 0;
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

static void		free_proj(t_proj *proj)
{
	int i;

	i = 0;
	while (i < proj->height)
	{
		free(proj->list[i]);
		i++;
	}
	free(proj->list);
}

int				main(int argc, char **argv)
{
	int		fd;
	t_proj	*proj;

	proj = new_proj();
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
	{
		ft_printf("Usage : ./fdf <filename>\n");
		exit(1);
	}
	read_file(fd, proj);
	proj->mlx_ptr = mlx_init();
	proj->win_ptr = mlx_new_window(proj->mlx_ptr, WIN_X, WIN_Y, "FdF");
	proj->win_image = mlx_new_image(proj->mlx_ptr, WIN_X, WIN_Y);
	display(proj);
	mlx_hook(proj->win_ptr, 2, 5, move, proj);
	mlx_hook(proj->win_ptr, 17, 1L << 17, exit_x, proj);
	mlx_loop(proj->mlx_ptr);
	free_proj(proj);
	return (0);
}
