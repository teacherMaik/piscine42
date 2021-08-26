/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:50:55 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/19 11:15:29 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_len(char *str);

int	ft_plus_minus(char *str);

int	ft_strstr(char *to_find);

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_plus_minus(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '+')
			return (0);
		else if (str[j] == '-')
			return (0);
		j++;
	}
	return (1);
}

int	ft_strstr(char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (to_find[i] && i < ft_str_len(to_find))
	{
		j = i + 1;
		while (to_find[j])
		{
			if (to_find[i] == to_find[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	a;
	int				b;
	int				d;
	int				r;

	if (nbr < 0)
		write (1, "-", 1);
	a = (nbr > 0) * nbr - (nbr < 0) * nbr;
	b = ft_str_len(base);
	d = a / b;
	r = a % b;
	if (ft_strstr(base))
	{
		if (b != 0 && b != 1)
		{
			if (ft_plus_minus(base))
			{
				if (d != 0)
					ft_putnbr_base(d, base);
				write (1, &base[r], 1);
			}
		}
	}
}
