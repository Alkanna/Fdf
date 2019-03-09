/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 00:00:06 by klouer            #+#    #+#             */
/*   Updated: 2018/02/13 00:31:53 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_sqrt(float nb)
{
	float	half;
	int		i;

	i = *(int*)(void*)(size_t)&nb;
	half = 0.5f * nb;
	i = 0x5f3759df - (i >> 1);
	nb = *(float*)(size_t)&i;
	nb = nb * (1.5f - half * nb * nb);
	return (nb);
}
