#include <libft.h>

void	ft_splitdel(char ***split)
{
	char	**str;
	int		i;

	i = 0;
	if (split)
	{
		str = *split;
		while (*str)
		{
			ft_strdel(str);
			i++;
			str = &(*split)[i];
		}
		ft_memdel((void **)split);
	}
}
