/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 13:34:39 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/14 13:34:50 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 47;
	while (++i <= 55 )
	{
		j = i;
		while (++j <= 56)
		{
			k = j;
			while (++k <= 57)
			{
				write (1, &i, 1);
				write (1, &j, 1);
				write (1, &k, 1);
				if (i != 55)
				{
					write (1, ",", 1);
					write (1, " ", 1);
				}
			}
		}
	}
}