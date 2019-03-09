/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:20:52 by klouer            #+#    #+#             */
/*   Updated: 2018/01/10 02:41:11 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinit(char *s1)
{
	char	*str;

	if (s1 == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + 1);
	ft_strcpy(str, s1);
	return (str);
}
