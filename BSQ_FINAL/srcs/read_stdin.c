/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoiron <mpoiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:56:17 by mpoiron           #+#    #+#             */
/*   Updated: 2021/08/26 11:42:24 by mpoiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_file.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

t_header	ft_readtitle_stdin(void)
{
	char		*str;
	t_header	header;
	int			ret;
	int			i;

	i = 0;
	str = malloc(14 * sizeof(*str));
	ret = read(0, str + i, 1);
	while (ret == 1 && str[i] != '\n' && i < 14)
		ret = read(0, str + ++i, 1);
	while (ret == 1 && str[i] != '\n' && i++ >= 14)
		ret = read(0, str + i, 1);
	if (i < 4 || ret == -1 || i >= 14 || str[i - 3] == str[i - 2]
		|| str[i - 3] == str[i - 1]
		|| str[i - 1] == str[i - 2])
		header.nb_lines = 0;
	else
	{
		header.empty = !(i < 4 || ret == -1) * str[i - 3];
		header.obstacle = !(i < 4 || ret == -1) * str[i - 2];
		header.full = !(i < 4 || ret == -1) * str[i - 1];
		header.nb_lines = !(i < 4 || ret == -1) * ft_atoi(str, str + i - 3);
	}
	free(str);
	return (header);
}

int	ft_readline_stdin(int fd, t_header *header, int i, t_list	**first)
{
	int		count;
	char	c;
	int		ret;
	t_point	point;

	count = 0;
	ret = read(fd, &c, 1);
	while (ret == 1 && c != '\n')
	{
		if (c == header->obstacle)
		{
			point.x = count;
			point.y = i;
			set_point(point, first);
		}
		else if (c != header->empty)
		{
			while (ret == 1 && c != '\n')
				ret = read(fd, &c, 1);
			return (-1);
		}
		count++;
		ret = read(fd, &c, 1);
	}
	return (ret * count);
}

void	ft_readmap_stdin(t_header *header)
{
	int		i;
	t_list	*first;
	int		n2;

	first = NULL;
	header->nb_col = ft_readline_stdin(0, header, 0, &first);
	i = 1;
	if (header->nb_col > 0)
	{
		n2 = header->nb_col;
		while (n2 == header->nb_col && i < header->nb_lines)
		{
			n2 = ft_readline_stdin(0, header, i, &first);
			i++;
		}
		if (i == header->nb_lines && n2 == header->nb_col)
		{
			header->first = first;
			return ;
		}
	}
	header->nb_lines = 0;
}

t_header	ft_stdin(void)
{
	t_header	header;

	header = ft_readtitle_stdin();
	if (header.nb_lines)
	{
		if (header.nb_lines)
		{
			ft_readmap_stdin(&header);
			return (header);
		}
	}
	header.nb_lines = 0;
	return (header);
}
