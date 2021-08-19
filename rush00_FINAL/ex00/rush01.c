/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 16:24:21 by danimart          #+#    #+#             */
/*   Updated: 2021/08/08 17:56:12 by danimart         ###   ########.fr       */
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
			if ((l == 1 & ch == 1) || (y != 1 && (ch == x && x != 1) && l == y))
				ft_putchar('/');
			else if ((l == 1 && ch == x) || (l == y && ch == 1))
				ft_putchar('\\');
			else if ((l != 1 && l != y) && (ch != 1 && ch != x))
				ft_putchar(' ');
			else
				ft_putchar('*');
			ch++;
		}
		l++;
		ft_putchar('\n');
	}
}
