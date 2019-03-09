/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:43:09 by klouer            #+#    #+#             */
/*   Updated: 2017/11/23 08:32:08 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *cpy;

	cpy = NULL;
	cpy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (cpy != NULL)
		ft_strcpy(cpy, s1);
	return (cpy);
}
