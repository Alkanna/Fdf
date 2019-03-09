/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:48:10 by klouer            #+#    #+#             */
/*   Updated: 2019/03/09 22:37:58 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

struct s_env
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_env;


void drawSquare(void *mlx_ptr, void *mlx_win, int xStart, int yStart, int xEnd, int yEnd, int color)
{
	int xBackup;

	xBackup = xStart;

	while (yStart <= yEnd)
	{
		mlx_pixel_put(mlx_ptr, mlx_win, xStart, yStart, color);
		xStart++;
		if (xStart == xEnd + 1)
		{
			yStart++;
			xStart = xBackup;
		}
	}
}

int main(void)
{
	void	*mlx_ptr;
	void	*mlx_win1;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if ((mlx_ptr = mlx_init()) == (void *) 0)
		return 0;
	mlx_win1 = mlx_new_window(mlx_ptr, 500, 500, "Weev\'s Fdf");
	while (y <= 50)
	{
		mlx_pixel_put(mlx_ptr, mlx_win1, x, y, 0xFFFF);
		x++;
		if (x == 501)
		{
			y++;
			x = 0;
		}
	}
	drawSquare(mlx_ptr, mlx_win1, 245, 245, 255, 255, 0xFFFF);
	drawSquare(mlx_ptr, mlx_win1, 450, 50, 475, 75, 0xCD5C5C);
	drawSquare(mlx_ptr, mlx_win1, 450, 90, 475, 95, 0xCD5C5C);
	mlx_loop(mlx_ptr);
}
