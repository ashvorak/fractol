/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:22:10 by oshvorak          #+#    #+#             */
/*   Updated: 2018/04/05 15:29:20 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	change_color(t_proj *proj, int key)
{
	int		x;
	int		y;
	char	*color;

	if (key == 15)
		color = ft_strdup("ff0000");
	else if (key == 5)
		color = ft_strdup("00ff00");
	else if (key == 11)
		color = ft_strdup("0000ff");
	else if (key == 3)
		color = ft_strdup("ffffff");
	y = 0;
	while (y < proj->height)
	{
		x = 0;
		while (x < proj->width)
		{
			proj->list[y][x].color = ft_atoi_base(color, 16);
			x++;
		}
		y++;
	}
	ft_strdel(&color);
}
