#include <stdio.h>

int	atoi_base2(char *str, char *base);

int	main(void)
{
	int	res;
	char	str[40] = "   	 +--+-78a3f6z8";
	char	base[40] = "012345678abcdef";

	res = atoi_base2(str, base);
	printf("%d", res); 

	return  (0);
}
