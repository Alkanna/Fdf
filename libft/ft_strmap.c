/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:56:36 by klouer            #+#    #+#             */
/*   Updated: 2017/11/23 08:06:59 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*mapstr;

	if (s == NULL || f == NULL)
		return (NULL);
	mapstr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mapstr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapstr[i] = f(s[i]);
		i++;
	}
	mapstr[i] = '\0';
	return (mapstr);
}
