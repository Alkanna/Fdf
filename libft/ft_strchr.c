/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 01:07:05 by klouer            #+#    #+#             */
/*   Updated: 2017/12/28 16:36:03 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cast_c;

	cast_c = (const char)c;
	i = 0;
	while (s[i] && s[i] != cast_c)
		i++;
	if (s[i] == cast_c)
		return ((char*)&s[i]);
	return (NULL);
}
