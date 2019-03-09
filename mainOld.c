#include "fdf.h"
#include <fcntl.h>
#include "libft/libft.h"
#include "mlx/mlx.h"
#include "math.h"

int		main(int ac, char **av)
{
	t_fdf	mine;
	void	*init;
	void	*window;

	if (ac == 2)
	{
		mine.name = av[1];
		mine.fd = open(mine.name, O_RDONLY);
		//		fdf(&mine);
	}
	else
	{
		init = mlx_init();
		window = mlx_new_window(init, 150, 150, "Title");
		while (1)
		{
			mlx_pixel_put(init, window, 100, 100, 255);
			mlx_pixel_put(init, window, 100, 99, 255);
			mlx_pixel_put(init, window, 100, 98, 255);
			mlx_pixel_put(init, window, 100, 97, 255);
			mlx_pixel_put(init, window, 100, 96, 255);
			mlx_pixel_put(init, window, 100, 95, 255);
			mlx_pixel_put(init, window, 100, 94, 255);
		}
		//		ft_putendl("usage: ./fdf file");
	}
	return (0);
}
