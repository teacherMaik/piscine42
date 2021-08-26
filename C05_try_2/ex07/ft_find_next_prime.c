/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:04:38 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/23 20:19:18 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int	nb)
{
	int	i;
	int	res;

	if (nb == 2147483647)
		return (nb);
	i = 2;
	while (i * i <= nb)
	{
		res = nb % i;
		if (res == 0)
			return (0);
		i++;
	}
	return (42);
}

int	ft_find_next_prime(int nb)
{
	int	j;

	j = nb;
	if (nb <= 1)
		return (2);
	if (nb == 2)
		return (2);
	while (!ft_is_prime(j))
	{
		j++;
	}
	return (j);
}
