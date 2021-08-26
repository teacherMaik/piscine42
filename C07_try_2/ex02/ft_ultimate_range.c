/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:22:19 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/26 11:43:29 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof (*tab) * (max - min));
	if (!range)
		return (-1);
	else
		tab = *range;
	i = 0;
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (max - min);
}
