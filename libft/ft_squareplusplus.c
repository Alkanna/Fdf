/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squareplusplus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:16:11 by klouer            #+#    #+#             */
/*   Updated: 2017/12/15 22:16:12 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_squareplusplus(char ***src, int c, int old, int len)
{
	char	**a;
	int		i;

	a = (char**)malloc(sizeof(char*) * (1 + len));
	a[len] = NULL;
	i = len;
	while (i--)
	{
		a[i] = ft_strnew(len);
		ft_memset(a[i], c, len);
		a[i][len] = '\0';
	}
	if (src == NULL)
		return (a);
	while (i++ < old - 1)
	{
		ft_memcpy(a[i], (*src)[i], old);
		free((*src)[i]);
	}
	free(*src);
	src = &a;
	return (a);
}
