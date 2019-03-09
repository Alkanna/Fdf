/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 07:30:42 by klouer            #+#    #+#             */
/*   Updated: 2017/11/30 02:08:39 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	if (s[i] != c && s[i])
	{
		i++;
		count++;
	}
	while (s[i] != '\0')
	{
		if (ft_strchr(s, (char)c) == NULL)
			return (1);
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	cw;
	char	**tab;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	cw = ft_count_word(s, c);
	if ((!(tab = (char **)malloc(sizeof(char *) * (cw + 1)))))
		return (NULL);
	while (s[i] && k < cw)
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		tab[k++] = ft_strsub(s, i, j);
		i += j;
	}
	tab[k] = NULL;
	return (tab);
}
