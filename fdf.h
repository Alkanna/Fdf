#ifndef FDF_H
# define FDF_H

# define XSIZE 1500
# define YSIZE 1500

typedef struct	s_vert
{
	double		x;
	double		y;
	double		z;
	double		w;
	int			color;
} t_vert;

typedef struct	s_map
{
	int			width;
	int			height;
	int			max_z;
	int			min_z;
	int			zbuf[XSIZE * YSIZE];
	t_vert		*verts;
	t_vert		*xverts;
} t_map;

typedef struct		s_fdf
{
	int				fd;
	char			*name;
	void			*instance;
	void			*win;
	t_map			map;
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
