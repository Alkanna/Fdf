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
#include <fcntl.h>

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

static int		free_lst_or_map(t_list **lst, t_map *map)
{
	t_list	*next;

	if (lst)
	{
		while (*lst)
		{
			next = (*lst)->next;
			ft_memdel(&(*lst)->content);
			ft_memdel((void **)lst);
			*lst = next;
		}
	}
	if (map)
	{
		ft_memdel((void **)&map->verts);
		ft_memdel((void **)&map->xverts);
	}
	return (1);
}

static t_vert	gen_vert(int row, int col, char *z_str, t_map *m)
{
	t_vert	new_v;

	new_v.x = (double)col;
	new_v.y = (double)row;
	new_v.z = (double)ft_atoi(z_str);
	new_v.w = 1;
	new_v.color = 0x00FFFFFF;
	m->max_z = (new_v.z > m->max_z) ? new_v.z : m->max_z;
	m->min_z = (new_v.z < m->min_z) ? new_v.z : m->min_z;
	return (new_v);
}

static int		fill_map(t_map *m, t_list *llst)
{
	int		row;
	int		col;
	char	**split;
	t_list	*cur_elem;

	cur_elem = llst;
	row = (m->height - 1);
	while (row >= 0)
	{
		col = 0;
		if ((split = ft_strsplit((char *)cur_elem->content, ' ')) == NULL)
			return (free_lst_or_map(&llst, m));
		while (col < m->width)
		{
			m->verts[row * m->width + col] = gen_vert(row, col, split[col], m);
			col++;
		}
		ft_splitdel(&split);
		row--;
		cur_elem = cur_elem->next;
	}
	ft_putchar('c');
	ft_putchar('c');
	ft_putchar('c');
	ft_putchar('c');
	ft_putchar('c');
	free_lst_or_map(&llst, NULL);
	return (0);
}

static int		get_lines(int fd, t_list **llst, t_map *map)
{
	ssize_t	ret;
	t_list	*new;
	char	*line;

	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (map->width == -1)
			map->width = (int)ft_num_words(line, ' ');
		else if (map->width != (int)ft_num_words(line, ' '))
			return (free_lst_or_map(llst, NULL));
		if ((new = ft_lstnew(line, ft_strlen(line) + 1)) == NULL)
			return (free_lst_or_map(llst, NULL));
		ft_lstadd(llst, new);
		map->height++;
		ft_strdel(&line);
	}
	if (map->width <= 0 || ret == -1)
		return (free_lst_or_map(llst, NULL));
	return (0);
}

int read_file(int fd, t_map *map)
{
	t_list	*line_lst;

	line_lst = NULL;
	map->width = -1;
	map->height = 0;
	map->max_z = -2147483648;
	map->min_z = 2147483647;
	if (get_lines(fd, &line_lst, map) == 1)
		return (1);
	map->verts = ft_memalloc(sizeof(t_vert) * map->width * map->height);
	map->xverts = ft_memalloc(sizeof(t_vert) * map->width * map->height);
	return (fill_map(map, line_lst));
}

int main(int argc, char **argv)
{

	int			x;
	int			fd;
	int			y;
	t_fdf		*mlx;
	t_newShape	*shape;

	if ((mlx = malloc(4 * sizeof(t_fdf))) == NULL)
		return (0);
	if (argc != 2)
	{
		write(2, "usage: ./fdf [target_file.fdf]\n", 31);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read_file(fd, &(mlx->map)) != 0)
	{
		write(2, "An error occurred reading the file. Is it valid? Maybe my fdf just sucks.\n", 75);
		return (1);
	}
	x = 0;
	y = 0;
	if ((mlx->instance = mlx_init()) == (void *) 0)
		return 0;
	mlx->win = mlx_new_window(mlx->instance, XSIZE, YSIZE, "Weev\'s Fdf");
	if ((shape = malloc(4 * sizeof(t_newShape))) == NULL)
		return (0);
	initWrapper(mlx, shape);
	mlx_key_hook(mlx->win, keydown_hook, &mlx);
	mlx_string_put(mlx->instance, mlx->win, 15, 15, 0xCD5C5C, "Quit: ESC");
	free(shape);
	mlx_loop(mlx->instance);
}
