/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:02:04 by klouer            #+#    #+#             */
/*   Updated: 2017/11/24 14:36:47 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		pos;
	int		length;

	i = 0;
	length = ft_strlen(needle);
	if (length == 0)
		return ((char*)haystack);
	while (haystack[i] && (length + i) <= len)
	{
		pos = 0;
		while (needle[pos] == haystack[pos + i])
		{
			if (pos == (length - 1))
				return ((char*)haystack + i);
			pos++;
		}
		i++;
	}
	return (NULL);
}
