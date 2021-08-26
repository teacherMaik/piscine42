/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:58:01 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/17 19:20:16 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_negative(int n)
{
	char	c;

	c = '-';
	if (n < 0)
	{
		write(1, &c, 1);
		return (-1);
	}
	return (1);
}

void	ft_putnbr(int nb)
{
	unsigned int	number;
	int				i;
	int				digit[10];

	number = is_negative(nb) * nb;
	if (nb == 0)
		write(1, "0", 1);
	i = 0;
	while (number != 0)
	{
		digit[i] = number % 10 + 48;
		number = number / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &digit[i], 1);
		i--;
	}
}
