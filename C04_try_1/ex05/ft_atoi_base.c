/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:48:32 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/26 17:57:04 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_plus_minus(char *str);

int	ft_strstr(char *str);

//int	ft_str_len(char *str);

int	ft_plus_minus(char *str)
{
    int j;

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

int ft_strstr(char *to_find)
{
    int i;
    int j;
	int	k;

    k = 0;
    while (to_find[k])
        k++;
    i = 0;
    while (to_find[i] && i < k)
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

/*int	ft_str_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}*/

/*char    *is_space(char *str)
{
    while ((*str <= 13 && *str >= 9) || *str == 32)
    {
        str++;
    }
    return (str);
}*/

/*char    *is_neg(char *str, int *sign)
{
    while (*str == 43 || *str == 45)
    {
        if (*str == 45)
            *sign = (*sign) * (-1);
        str++;
    }
    return (str);
}*/

int ft_atoi(char *str)
{
    int sign;
    int res;

    sign = 1;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	while (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = (sign) * (-1);
		str++;
    }
    res = 0;
    while (*str <= 57 && *str >= 48)
    {
        res = res * 10 + *str - 48;
        str++;
    }
    return (res * sign);
}

void    ft_putnbr_base(int nbr, char *base)
{
    unsigned int    a;
    int             b;
    int             d;
    int             r;
	int 			i;

    i = 0;
    while (base[i])
        i++;
    if (nbr < 0)
        write (1, "-", 1);
    a = (nbr > 0) * nbr - (nbr < 0) * nbr;
    b = i;
    d = a / b;
    r = a % b;
    if (ft_strstr(base) && (b !=0 && b != 1))
    {
		if (ft_plus_minus(base) && d != 0)
		{
			ft_putnbr_base(d, base);
			write (1, &base[r], 1);
		}
	}
}

void    ft_atoi_base(char *str, char *base)
{
	int	nbr;

	nbr = ft_atoi(str);
	ft_putnbr_base(nbr, base);
}
