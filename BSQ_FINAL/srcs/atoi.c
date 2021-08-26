/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoiron <mpoiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:10:27 by mpoiron           #+#    #+#             */
/*   Updated: 2021/08/24 16:11:13 by mpoiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_file.h"

int	ft_strncmp(char	*s1, char	*s2, unsigned int	n)
{
	int				sum;
	unsigned int	ind;

	ind = 0;
	sum = 0;
	while (s1[ind] != '\0' && s2[ind] != '\0' && ind < n)
	{
		if (s1[ind] != s2[ind])
			return (s1[ind] - s2[ind]);
		ind++;
	}
	if (s1[ind] != '\0' && ind < n)
		return (s1[ind]);
	if (s2[ind] != '\0' && ind < n)
		return (-s2[ind]);
	return (0);
}

int	ft_is_space(char c)
{
	int	res;

	res = 0;
	if (c == '\t' || c == '\n' || c == '\v')
		res = 1;
	else if (c == '\f' || c == '\r' || c == ' ')
		res = 1;
	return (res);
}

unsigned int	ft_atoi(char *str, char *str2)
{
	int				i;
	unsigned int	sum;

	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	sum = 0;
	if (str2 - str > 10 || (str2 - str == 10
			&& ft_strncmp(str, "2147483647", 10) > 0))
		return (0);
	while (str[i] && (str[i] >= '0' && str[i] <= '9') && str + i != str2)
	{
		sum = 10 * sum;
		sum = sum + str[i] - '0';
		i++;
	}
	if (str + i != str2)
		return (0);
	return (sum);
}
