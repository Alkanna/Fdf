/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:19:13 by klouer            #+#    #+#             */
/*   Updated: 2017/11/23 08:01:06 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cast_s;

	i = -1;
	cast_s = (unsigned char *)s;
	if (n == 0)
		return (s);
	while (++i < n)
		cast_s[i] = (unsigned char)c;
	return (s);
}
