/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:07:01 by oshvorak          #+#    #+#             */
/*   Updated: 2018/04/04 17:52:07 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		make_color(t_proj *proj, int x, int y, char *arr)
{
	char	*tmp;

	if (ft_strstr(arr, ","))
	{
		tmp = ft_strchr(arr, ',');
		proj->list[y][x].color = ft_atoi_base(&tmp[3], 16);
	}
	else
		proj->list[y][x].color = 0;
}

void			make_list(t_proj *proj, char *buf)
{
	int		i;
	int		x;
	int		y;
	char	**arr;

	i = 0;
	y = 0;
	arr = ft_strsplit(buf, ' ');
	proj->list = (t_coor**)malloc(sizeof(t_coor*) * proj->width * proj->height);
	while (y < proj->height)
	{
		x = 0;
		proj->list[y] = (t_coor*)malloc(sizeof(t_coor) * proj->width);
		while (x < proj->width)
		{
			proj->list[y][x].x = x;
			proj->list[y][x].y = y;
			proj->list[y][x].z = ft_atoi(arr[i]);
			make_color(proj, x, y, arr[i]);
			x++;
			i++;
		}
		y++;
	}
	free_arr(arr);
}
