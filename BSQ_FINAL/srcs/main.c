/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoiron <mpoiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:11:47 by mpoiron           #+#    #+#             */
/*   Updated: 2021/08/26 14:37:54 by mpoiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_file.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_worker(char *name, int nb)
{
	t_header	header;
	t_header	header2;
	t_result	res;

	if (nb > 1)
		header = ft_openfile(name);
	else
		header = ft_stdin();
	if (!header.nb_lines)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	res.point.x = 0;
	res.point.y = 0;
	res.length = -1;
	header2 = header;
	ft_solve(0, res.point, header2, &res);
	ft_print(res, header);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	nb;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			nb = ft_worker(argv[i], argc);
			i++;
			if (argc > 2 && nb == 1)
				write(1, "\n", 1);
		}
	}
	else
		ft_worker(NULL, 1);
	return (0);
}
