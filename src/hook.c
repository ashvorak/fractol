/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:30:25 by oshvorak          #+#    #+#             */
/*   Updated: 2018/07/27 17:22:35 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static double interpolate(double start, double end, double interpolation)
{
    return (start + ((end - start) * interpolation));
}

void applyZoom(t_proj* proj, double mouseRe, double mouseIm, double zoomFactor)
{
    double interpolation;
	interpolation = 1.0 / zoomFactor;
    proj->Re_min = interpolate(mouseRe, proj->Re_min, interpolation);
    proj->Im_min = interpolate(mouseIm, proj->Im_min, interpolation);
    proj->Re_max = interpolate(mouseRe, proj->Re_max, interpolation);
    proj->Im_max = interpolate(mouseIm, proj->Im_max, interpolation);
}

int 	manage_mouse(int mousecode, int x, int y, t_proj *proj)
{
	double mouseRe;
	double mouseIm;

	mouseRe = (double)x / (WIN / (proj->Re_max - proj->Re_min)) + proj->Re_min;
	mouseIm = (double)y / (WIN / (proj->Im_max - proj->Im_min)) + proj->Im_min;
	if (mousecode == 5 || mousecode == 2)
	{
		applyZoom(proj, mouseRe, mouseIm, 1.1);
		proj->iteration_max++;
	}
	else if (mousecode == 4 || mousecode == 1)
	{
		applyZoom(proj, mouseRe, mouseIm, 0.9);
		(proj->iteration_max > 2) ? proj->iteration_max-- : 0;
	}
	display(proj);
	return (0);
}

int		manage_mouse_julia(int x, int y, t_proj *proj)
{
	if (proj->fractol == Julia && (x > 0 && x <= 1000) && (y > 0 && y <= 1000) && proj->move_julia)
	{
		proj->c_re_j = (double)x / (double)WIN * 4.0 - 2.0;
		proj->c_im_j = (double)y / ((double)WIN) * 4.0 - 2.0;
		display(proj);
	}
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
