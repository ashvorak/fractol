/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:30:25 by oshvorak          #+#    #+#             */
/*   Updated: 2018/07/25 18:32:45 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

void applyZoom(t_proj* proj, double mouseRe, double mouseIm, double zoomFactor)
{
    double interpolation = 1.0 / zoomFactor;
    proj->Re_min = interpolate(mouseRe, proj->Re_min, interpolation);
    proj->Im_min = interpolate(mouseIm, proj->Im_min, interpolation);
    proj->Re_max = interpolate(mouseRe, proj->Re_max, interpolation);
    proj->Im_max = interpolate(mouseIm, proj->Im_max, interpolation);
}

int 	manage_mouse(int mousecode, int x, int y, t_proj *proj)
{
	double mouseRe = (double)x / (WIN / (proj->Re_max - proj->Re_min)) + proj->Re_min;
	double mouseIm = (double)y / (WIN / (proj->Im_max - proj->Im_min)) + proj->Im_min;

	if (mousecode == 5 || mousecode == 2)
	{
		applyZoom(proj, mouseRe, mouseIm, 1.1);
		proj->iteration_max++;
	}
	else if (mousecode == 4 || mousecode == 1)
	{
		applyZoom(proj, mouseRe, mouseIm, 0.9);
		proj->iteration_max--;
	}
	display(proj);
	return (0);
}

int		manage_keys(int key, t_proj *proj)
{
	if (key == 53)
		exit(1);
	else if (key == 78)
	{
		key++;
		(proj->iteration_max > 1) ? proj->iteration_max -= 1 : 0;
	}
	else if (key == 69)
	{
		key++;
	}
	display(proj);
	return (0);
}
