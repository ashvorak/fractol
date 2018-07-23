/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:30:25 by oshvorak          #+#    #+#             */
/*   Updated: 2018/07/23 18:42:45 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int manage_mouse(int mousecode, int x, int y, t_proj *proj)
{
	if (mousecode == 4 || mousecode == 1)
	{
		proj->zy += 0.1;
	}
	else if (mousecode == 5 || mousecode == 2)
	{
		(proj->zy - 0.1 >= 0) ? proj->zy -= 0.1 : 0;
	}
	x = 0;
	y = 0;
	display(proj);
	return (0);
}

int manage_keys(int key, t_proj *proj)
{
	if (key == 53)
		exit(1);
	else if (key == 78)
	{
		proj->zy += 0.1;
		(proj->iteration_max > 1) ? proj->iteration_max -= 1 : 0;
	}
	else if (key == 69)
	{
		(proj->zy - 0.1 >= 0) ? proj->zy -= 0.1 : 0;
		//proj->iteration_max += 1;
	}
	display(proj);
	return (0);
}
