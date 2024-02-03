/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 13:34:39 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/14 13:34:50 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int	i; //1st digit of number
	int	j; //2cnd digit of number
	int	k; //3rd digit of number

	i = 47; //start first digit at ASCII previous to "0"
	while (++i <= 55 ) //Up "i" before the logical comparison
	{
		j = i; //Set "j" to "i"
		while (++j <= 56) //Up "j" before the logical comparison so it is 1 more than "i"
		{
			k = j; //Set "k" to "j"
			while (++k <= 57) //Up "k" before the logical comparison so it is 1 more than "j" and 2 more than "i"
			{
				write (1, &i, 1); //Three writes to print the 3 digit number on the terminal line
				write (1, &j, 1);
				write (1, &k, 1);
				if (i != 55)  //checks to see if "i" is 7, which will be last valid number (789). If not, add ", " to terminal line to seperate numbers
				{
					write (1, ",", 1);
					write (1, " ", 1);
				}
			}
		}
	}
}
