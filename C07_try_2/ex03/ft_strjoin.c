/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:15:55 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/25 10:50:38 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strslen(char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;
	int	res;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		res = res + j;
		i++;
	}
	k = 0;
	while (sep[k])
		k++;
	res = res + (k * (size - 1)) + 1;
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*joined;
	char	*joined_copy;

	if (size == 0)
	{	
		joined = (char *)malloc(sizeof (*joined) * 2);
		return (joined);
	}
	joined = (char *)malloc(sizeof (*joined) * ft_strslen(strs, sep, size));
	joined_copy = joined;
	i = -1;
	while (++i < size)
	{
		k = -1;
		j = -1;
		while (strs[i][++j])
			*(joined++) = strs[i][j];
		while (sep[++k] && i < size - 1)
			*(joined++) = sep[k];
	}
	*joined = '\0';
	return (joined_copy);
}
