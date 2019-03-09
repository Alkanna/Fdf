/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 00:35:37 by klouer            #+#    #+#             */
/*   Updated: 2018/01/25 00:40:17 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2, int mode)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
	{
		str = (s1) ? ft_strdup(s2) : ft_strdup(s2);
		((mode == 1 || mode > 2) ? ft_strdel((char**)&s1) : 0);
		if (mode >= 2)
			ft_strdel((char**)&s2);
		return (str);
	}
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	((mode == 1 || mode > 2) ? ft_strdel((char**)&s1) : 0);
	if (mode >= 2)
		ft_strdel((char**)&s2);
	return (str);
}
