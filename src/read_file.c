/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:27:58 by oshvorak          #+#    #+#             */
/*   Updated: 2018/04/04 17:16:24 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static void	scaling(t_proj *proj)
{
	double scale;

	if (WIN_X - proj->list[0][proj->width - 1].x > \
	WIN_Y - proj->list[proj->height - 1][0].y)
		scale = WIN_X / proj->list[0][proj->width - 1].x;
	else
		scale = WIN_Y / proj->list[proj->height - 1][0].y;
	scale = (scale / 100) * SCALE;
	zoom(proj, scale);
	centering(proj, WIN_X / 2 - (proj->list[0][proj->width - 1].x + \
		proj->list[0][0].x) / 2, WIN_Y / 2 - \
		(proj->list[proj->height - 1][0].y + proj->list[0][0].y) / 2);
}

static void	check_width(char *line, int width)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_strsplit(line, ' ');
	while (arr[i])
		i++;
	if (i != width)
	{
		perror("Wrong field size");
		exit(1);
	}
	free_arr(arr);
}

static char	*ret_buf(t_proj *proj, int fd, char *buf)
{
	char	*line;
	char	*tmp;

	tmp = ft_strdup(buf);
	ft_strdel(&buf);
	buf = ft_strjoin(tmp, " ");
	ft_strdel(&tmp);
	proj->height = 1;
	while (get_next_line(fd, &line))
	{
		tmp = ft_strdup(buf);
		ft_strdel(&buf);
		check_width(line, proj->width);
		buf = ft_strjoin(tmp, line);
		ft_strdel(&tmp);
		tmp = ft_strdup(buf);
		ft_strdel(&buf);
		buf = ft_strjoin(tmp, " ");
		ft_strdel(&tmp);
		ft_strdel(&line);
		proj->height++;
	}
	return (buf);
}

void		read_file(int fd, t_proj *proj)
{
	int		i;
	char	*buf;
	char	*line;
	char	**arr;

	i = 0;
	if (get_next_line(fd, &line) == -1)
	{
		perror("No such file");
		exit(1);
	}
	buf = ft_strdup(line);
	ft_strdel(&line);
	arr = ft_strsplit(buf, ' ');
	proj->width = 0;
	while (arr[i++])
		proj->width++;
	free_arr(arr);
	buf = ret_buf(proj, fd, buf);
	make_list(proj, buf);
	rotation(proj, 2, 10 * M_PI / 180);
	rotation(proj, 13, 10 * M_PI / 180);
	scaling(proj);
	ft_strdel(&buf);
}
