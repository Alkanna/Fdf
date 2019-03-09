/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:19:30 by klouer            #+#    #+#             */
/*   Updated: 2017/11/23 08:07:12 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mapstr;

	if (s == NULL || f == NULL)
		return (NULL);
	mapstr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mapstr == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		mapstr[i] = f(i, s[i]);
	mapstr[i] = '\0';
	return (mapstr);
}
