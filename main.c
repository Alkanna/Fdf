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

#include "mlx/mlx.h"
#include "./fdf.h"
#include <stdlib.h>
#include "libft/libft.h"

#define XSIZE 1500
#define YSIZE 1500

/*
** Function to catch ESC key and exit properly
*/

void clean_exit(t_fdf *mlx)
{
	mlx_destroy_image(mlx->instance, mlx->win);
}

int  keydown_hook(int keycode, t_fdf *mlx)
{
	if (keycode == 53)
	{
		mlx->fd = 1;
//		clean_exit(mlx);
		exit(0);
	}
	else
		return (0);
}

/*
** Initialisation of the interface wrapper
*/

void initWrapper(t_fdf *mlx, t_newShape *shape)
{
	shape[0] = (t_newShape){0, 0, XSIZE, 50};
	drawShape(mlx, *shape, 0xFFFF);
	shape[0] = (t_newShape){0, XSIZE - 50, XSIZE, XSIZE};
	drawShape(mlx, *shape, 0xFFFF);
}

/*
** Function used to draw a shape using 2 points named start and end with their respective x and y axis
*/

void drawShape(t_fdf *mlx, t_newShape shape, int color)
{
	int xBackup;

	xBackup = shape.xStart;

	while (shape.yStart <= shape.yEnd)
	{
		mlx_pixel_put(mlx->instance, mlx->win, shape.xStart, shape.yStart, color);
		shape.xStart++;
		if (shape.xStart == shape.xEnd + 1)
		{
			shape.yStart++;
			shape.xStart = xBackup;
		}
	}
}

int main(void)
{

	int		x;
	int		y;
	t_fdf *mlx;
	t_newShape *shape;

	if ((mlx = malloc(4 * sizeof(t_fdf))) == NULL)
		return (0);
	x = 0;
	y = 0;
	if ((mlx->instance = mlx_init()) == (void *) 0)
		return 0;
	mlx->win = mlx_new_window(mlx->instance, XSIZE, YSIZE, "Weev\'s Fdf");
	if ((shape = malloc(4 * sizeof(t_newShape))) == NULL)
		return (0);
	initWrapper(mlx, shape);
	//	drawSquare(mlx->instance, mlx->win, 450, 50, 475, 75, 0xCD5C5C);
	//	drawSquare(mlx->instance, mlx->win, 450, 90, 475, 95, 0xCD5C5C);
	mlx_key_hook(mlx->win, keydown_hook, &mlx);
	mlx_string_put(mlx->instance, mlx->win, 15, 15, 0xCD5C5C, "Quit: ESC");
	free(shape);
	mlx_loop(mlx->instance);
}
