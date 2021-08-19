/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 19:48:06 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/16 13:51:40 by mbennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	alphanumeric(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (alphanumeric(str[i]))
		{
			if (str[i] <= 122 && str[i] >= 97)
			{
				str[i] = str[i] - 32;
			}
			i++;
			while (alphanumeric(str[i]) && i != 0)
			{
				if (str[i] >= 65 && str[i] <= 90)
					str[i] = str[i] + 32;
				i++;
			}
		}
		i++;
	}
	return (str);
}
