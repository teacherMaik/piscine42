/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:57:58 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/21 15:35:48 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 2147483647)
		return (0);
	else if (nb >= 1)
		return (nb = nb * ft_recursive_factorial(nb - 1));
	else
		return (1);
}
