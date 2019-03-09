/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:12:59 by klouer            #+#    #+#             */
/*   Updated: 2017/12/15 22:13:00 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget(t_list *lst, const void *value, int (*cmp)(const void *,
		const void *))
{
	t_list	*current;

	current = lst;
	while (current)
	{
		if (cmp(current->content, value))
			return (current);
		current = current->next;
	}
	return (NULL);
}
