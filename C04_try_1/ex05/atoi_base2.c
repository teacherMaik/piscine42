int	ft_power(int nb, int power)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	while (i < power)
	{
		res = res * nb;
		i++;
	}
	return (res);
}

int	ft_mates(char *str, char *base)
{
	int	base_len;
	int	str_len;
	int	i;
	int j;
	int	res;

	str_len = 0;
	base_len = 0;
	while (str[str_len])
		str_len++;
	while (base[base_len])
		base_len++;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				res = j * (ft_power(base_len, str_len - i - 1)) + res;
			j++;
		}
		i++;
	}
	return (res);
}

int	ft_strstr(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_num_string(char *str, char *base)
{
	int		i;
	int		sign;
	char	*aux;

	aux = str;
	sign = 1;
	while (*str && ((*str <= 13 && *str >= 9) || *str == 32))
		str++;
	while (*str && (*str == 45 || *str == 43))
	{
		if (*str ==  45)
			sign = sign * (-1);
		str++;
	}	
	i= 0;
	while ((str[i] <= 57 && str[i] >= 48) && ft_strstr(str[i], base))
	{
		aux[i] = str[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

int	atoi_base2(char *str, char *base)
{
	int		i;
	int		j;
	char	*num;
	int		res;

	i = 0;
	while (base[i])
	{
		if (base[i] == 43 || base[i] ==  45)
		   return (0);
		i++;	
	}
	if (i <= 1)
		return (0);
	num = ft_get_num_string(str, base);
	res = ft_mates(num, base);
	if (res  > 2147483647)
		return (0);
	else
		return (res);
}
