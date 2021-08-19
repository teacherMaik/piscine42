/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:55:52 by danimart          #+#    #+#             */
/*   Updated: 2021/08/08 17:56:01 by danimart         ###   ########.fr       */
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
			if ((l == 1 || l == y) && (ch == 1 || ch == x))
				ft_putchar('o');
			else if (l == 1 || l == y)
				ft_putchar('-');
			else if (ch == 1 || ch == x)
				ft_putchar('|');
			else
				ft_putchar(' ');
			ch++;
		}
		ft_putchar('\n');
		l++;
	}
}
