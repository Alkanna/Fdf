/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:53:58 by klouer            #+#    #+#             */
/*   Updated: 2018/01/28 22:03:41 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(int const fd, char *buffer, char *save[fd])
{
	int				ret;
	char			*tmp;

	while (ft_strchr(buffer, '\n') == NULL &&
			(ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = save[fd];
		save[fd] = ft_strjoinfree(tmp, buffer, 1);
	}
	ft_strdel(&buffer);
	return (ret == -1 ? -1 : 0);
}

int			get_next_line(int const fd, char **line)
{
	static char		*save[MAX_FD];
	char			*buffer;
	char			*str;
	char			*tmp;

	buffer = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || buffer == NULL || BUFF_SIZE < 1)
		return (-1);
	if (save[fd] == NULL)
		save[fd] = ft_strnew(1);
	if (get_line(fd, buffer, save) == -1)
		return (-1);
	if ((str = ft_strchr(save[fd], '\n')) != NULL)
	{
		*line = ft_strsub(save[fd], 0, str - save[fd]);
		tmp = save[fd];
		save[fd] = ft_strdup(str + 1);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strdup(save[fd]);
	save[fd] = NULL;
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
