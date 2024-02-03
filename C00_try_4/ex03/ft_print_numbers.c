/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 13:33:59 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/14 13:34:02 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	i; //Declares variable "i" for "integer"

	i = 48; //startat ASCII 48 which is the digit 0

	while (i <= 57)
	{
		write (1, &i, 1);
		i++;
	}
}
