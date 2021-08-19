/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 16:24:37 by danimart          #+#    #+#             */
/*   Updated: 2021/08/08 17:56:40 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	ch;
	int	l;

	l = 1;
	while (l <= y)
	{
		ch = 1;
		while (ch <= x)
		{
			if ((l == 1) && (ch == 1 || ch == x))
				ft_putchar('A');
			else if ((l == y) && (ch == 1 || ch == x))
				ft_putchar('C');
			else if ((l != 1 && l != y) && ch != 1 && ch != x)
				ft_putchar(' ');
			else
				ft_putchar('B');
			ch++;
		}
		l++;
		ft_putchar('\n');
	}
}
