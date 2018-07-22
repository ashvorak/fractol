#include "../inc/fractol.h"

int manage_mouse(int mousecode)
{
	if (mousecode == 4 || mousecode == 1)
	{
		ft_printf("check1\n");
	}
	else if (mousecode == 5 || mousecode == 2)
	{
		ft_printf("check2\n");
	}
	ft_printf("check3\n");
	return (0);
}

int manage_keys(int key, t_proj *proj)
{
	if (key == 53)
		exit(1);
	else if (key == 69)
	{
		proj->zx += 0;
		proj->zy += 0;
		proj->iteration_max += 1;
	}
	else if (key == 78)
	{
		proj->zx -= 0;
		proj->zy -= 0;
		proj->iteration_max -= 1;
	}
	display(proj);
	return (0);
}
