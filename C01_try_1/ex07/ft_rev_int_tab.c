/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:52:54 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/11 17:59:09 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (i < size / 2)
	{
		p = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = p;
		i++;
	}
}
