/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 13:32:54 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/14 13:33:02 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void) //Void takes no parameters
{
	char	l; //Declare char with "l" for "letter"

	l = 97; //87 is the ASCII number for the letter "a"
	while (l <= 122) //Loop until letter "z"
	{
		write (1, &l, 1); //Write 1 char represented by "l" on terminal line
		l++; //up variable number to go to next letter in alphabet
	}
}
