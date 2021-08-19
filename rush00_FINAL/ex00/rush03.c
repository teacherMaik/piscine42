/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 11:46:42 by danimart          #+#    #+#             */
/*   Updated: 2021/08/08 15:05:35 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	l;
	int	ch;

	l = 1;
	while (l <= y)
	{
		ch = 1;
		while (ch <= x)
		{
			if ((l == 1 || l == y) && ch == 1)
				ft_putchar('A');
			else if ((l == 1 || l == y) && ch == x)
				ft_putchar('C');
			else if (ch == 1 || ch == x || l == 1 || l == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			ch++;
		}
		ft_putchar('\n');
		l++;
	}
}
