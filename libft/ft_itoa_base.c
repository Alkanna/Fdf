/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:12:48 by klouer            #+#    #+#             */
/*   Updated: 2017/12/15 22:12:49 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base(int n, int b)
{
	char	*a;
	int		i;
	int		negative;

	negative = 0;
	a = (char*)malloc(sizeof(char) * 34);
	if (n == 0)
	{
		a[0] = '0';
		a[1] = '\0';
	}
	if (b == 10 && n < 0)
		negative = 1;
	i = 0;
	while (1)
	{
		a[i++] = ft_abs(n % b) > 9 ? ft_abs(n % b) + 55 : ft_abs(n % b)
		+ '0';
		if (!(n /= b))
			break ;
	}
	if (negative)
		a[i++] = '-';
	a[i] = '\0';
	return (ft_strrev(a));
}
