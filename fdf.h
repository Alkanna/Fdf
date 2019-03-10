#ifndef FDF_H
# define FDF_H

# define ESC 27

typedef struct		s_fdf
{
	int				fd;
	char			*name;
	void			*instance;
	void			*win;
}					t_fdf;

typedef struct		s_newShape
{
	int				xStart;
	int				yStart;
	int				xEnd;
	int				yEnd;
}					t_newShape;

int keydown_hook(int keycode, t_fdf *mlx);
void initWrapper(t_fdf *mlx, t_newShape *shape);
void drawShape(t_fdf *mlx, t_newShape shape, int color);

#endif
