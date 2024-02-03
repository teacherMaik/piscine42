/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 13:33:22 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/14 13:33:45 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	l;

	l = 122; //Does same a ft_print reverse starting with ASCII "z" and going down
	while (l >= 97)
	{
		write (1, &l, 1);
		l--; //instead of increment up increment down
	}
}
