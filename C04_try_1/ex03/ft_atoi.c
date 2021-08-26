/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:06:02 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/19 11:16:12 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*is_space(char *str)
{
	while ((*str <= 13 && *str >= 9) || *str == 32)
	{
		str++;
	}
	return (str);
}

char	*is_neg(char *str, int *sign)
{
	while (*str == 43 || *str == 45)
	{
		if (*str == 45)
			*sign = (*sign) * (-1);
		str++;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	sign = 1;
	str = is_space(str);
	str = is_neg(str, &sign);
	res = 0;
	while (*str <= 57 && *str >= 48)
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * sign);
}
