/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 13:34:24 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/14 13:34:26 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n) //Recieves an integer as a parameter
{
	int	i; 

	i = n;
	if (i >= 0) //Tests to see if integer is greater than 0
	{
		write (1, "P", 1); //Writes "P" on terminal line if positive
	}
	else
	{
		write (1, "N", 1); //Writes "N" on terminal if negative
	}
}

