/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:41:41 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/21 13:51:10 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	i = nb;
	res = 1;
	if (nb < 0 || nb >= 2147483647)
		return (0);
	else if (nb == 0)
		return (1);
	while (i > 0)
	{
		res = res * i;
		i--;
	}
	return (res);
}
