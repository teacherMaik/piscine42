/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 13:38:33 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/14 14:37:23 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int a, int b, int c, int d);

void	ft_comb(int a, int b, int c, int d);

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = 48;
	b = 48;
	c = 48;
	d = 48;
	ft_comb(a, b, c, d);
}

void	ft_putnbr(int a, int b, int c, int d)
{
	if (a * 10 + b < c * 10 + d)
	{
		write (1, &a, 1);
		write (1, &b, 1);
		write (1, " ", 1);
		write (1, &c, 1);
		write (1, &d, 1);
		if (a != 57 || b != 56 || c != 57 || d != 57)
			write (1, ", ", 2);
	}
}

void	ft_comb(int a, int b, int c, int d)
{
	while (a <= 57)
	{
		while (b <= 57)
		{
			while (c <= 57)
			{
				while (d <= 57)
				{
					ft_putnbr(a, b, c, d);
					d++;
				}
				d = 48;
				c++;
			}
			c = 48;
			b++;
		}
		b = 48;
		a++;
	}
}
