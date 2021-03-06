/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:11:55 by klouer            #+#    #+#             */
/*   Updated: 2017/12/15 22:11:56 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while (s[i])
		i++;
	i--;
	j = 0;
	while (j < i)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i--;
		j++;
	}
	return (s);
}
