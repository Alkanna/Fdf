/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:12:14 by klouer            #+#    #+#             */
/*   Updated: 2017/12/15 22:12:15 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *s, int b)
{
	int		n;
	int		negative;
	int		i;
	int		exp;

	exp = 0;
	i = 0;
	negative = 1;
	n = 0;
	if (*s == '-')
	{
		i++;
		negative = -1;
	}
	while (s[i])
		i++;
	while (--i >= 0)
	{
		if (ft_ctoi(s[i]) != -1 && ft_ctoi(s[i]) < b)
			n += ft_ctoi(s[i]) * ft_pow(b, exp++);
	}
	return (n * negative);
}
