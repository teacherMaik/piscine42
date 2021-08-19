/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:54:24 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/14 19:05:21 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_negative(int	n)
{
	char	c;

	c = '-';
	if (n < 0)
	{
		write (1, &c, 1);
		return (-1);
	}
	return (1);
}

void	ft_putnbr(int n)
{
	int				i;
	int				digit[10];
	unsigned int	s;
	char			z;

	z = 48;
	s = ft_is_negative(n) * n;
	if (n == 0)
		write (1, &z, 1);
	i = 0;
	while (s != 0)
	{
		digit[i] = s % 10 + 48;
		s = s / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write (1, &digit[i], 1);
		i--;
	}
}
