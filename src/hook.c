/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:30:25 by oshvorak          #+#    #+#             */
/*   Updated: 2018/07/28 17:07:29 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int			exit_x(t_proj *proj)
{
	free(proj);
	exit(0);
}

static void	zoom(t_proj *proj, double m_re, double m_im, double k)
{
	double q;

	q = 1.0 / k;
	proj->re_min = m_re + ((proj->re_min - m_re) * q);
	proj->im_min = m_im + ((proj->im_min - m_im) * q);
	proj->re_max = m_re + ((proj->re_max - m_re) * q);
	proj->im_max = m_im + ((proj->im_max - m_im) * q);
}

int			manage_mouse(int m_click, int x, int y, t_proj *proj)
{
	double m_re;
	double m_im;

	m_re = (double)x / (WIN / (proj->re_max - proj->re_min)) + proj->re_min;
	m_im = (double)y / (WIN / (proj->im_max - proj->im_min)) + proj->im_min;
	if (m_click == 5 || m_click == 2)
	{
		zoom(proj, m_re, m_im, 1.1);
		proj->iteration_max++;
	}
	else if (m_click == 4 || m_click == 1)
	{
		zoom(proj, m_re, m_im, 0.9);
		(proj->iteration_max > 2) ? proj->iteration_max-- : 0;
	}
	display(proj);
	return (0);
}

int			manage_mouse_julia(int x, int y, t_proj *proj)
{
	if (proj->fractol == Julia && (x > 0 && x <= 1000) \
	&& (y > 0 && y <= 1000) && proj->move_julia)
	{
		proj->c_re_j = (double)x / (double)WIN * 4.0 - 2.0;
		proj->c_im_j = (double)y / ((double)WIN) * 4.0 - 2.0;
		display(proj);
	}
	return (0);
}

int			manage_keys(int key, t_proj *proj)
{
	if (key == 53)
	{
		free(proj);
		exit(1);
	}
	else if (key == 78)
		proj->iteration_max -= (proj->iteration_max > 1) ? 1 : 0;
	else if (key == 69)
		proj->iteration_max += (proj->iteration_max < 1000) ? 1 : 0;
	else if (key == 3 && proj->fractol == Julia)
		proj->move_julia = 0;
	else if (key == 5 && proj->fractol == Julia)
		proj->move_julia = 1;
	else if (key == 18)
		proj->color = 16752762;
	else if (key == 19)
		proj->color = 65407;
	else if (key == 20)
		proj->color = 2003199;
	display(proj);
	return (0);
}
