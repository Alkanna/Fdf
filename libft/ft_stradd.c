/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:16:03 by klouer            #+#    #+#             */
/*   Updated: 2017/12/15 22:16:04 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_stradd(char **dest, char *src)
{
	int		size;
	char	*s;

	size = ft_strlen(*dest) + ft_strlen(src) + 1;
	s = ft_strnew(size);
	if (s == NULL)
		return (NULL);
	if (*dest != NULL)
	{
		ft_strcpy(s, *dest);
		free(*dest);
	}
	ft_strcat(s, src);
	*dest = s;
	return (s);
}
