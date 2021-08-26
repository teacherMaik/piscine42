/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoiron <mpoiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:10:38 by mpoiron           #+#    #+#             */
/*   Updated: 2021/08/26 11:46:46 by mpoiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_file.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

t_header	ft_readtitle(int fd)
{
	char		*str;
	t_header	header;
	int			ret;
	int			i;

	i = 0;
	str = malloc(14 * sizeof(*str));
	ret = read(fd, str + i, 1);
	while (ret == 1 && str[i] != '\n' && i < 14)
		ret = read(fd, str + ++i, 1);
	if (i < 4 || ret == -1 || str[i - 3] == str[i - 1] || str[i] != '\n')
		header.nb_lines = 0;
	else if (str[i - 3] == str[i - 2] || str[i - 1] == str[i - 2])
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

int	ft_readline(int fd, t_header *header, int i, t_list	**first)
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
			return (-1);
		count++;
		ret = read(fd, &c, 1);
	}
	if (ret == -1)
		count = 1;
	return (ret * count);
}

void	ft_readmap(int fd, t_header *header)
{
	int		i;
	t_list	*first;
	int		n2;

	first = NULL;
	header->nb_col = ft_readline(fd, header, 0, &first);
	i = 1;
	n2 = header->nb_col;
	if (header->nb_col > 0)
	{
		while (n2 == header->nb_col)
		{
			n2 = ft_readline(fd, header, i, &first);
			i++;
		}
		if (i == header->nb_lines + 1 && n2 == 0)
		{
			header->first = first;
			return ;
		}
	}
	header->nb_lines = 0;
}

t_header	ft_openfile(char *name)
{
	int			fd;
	t_header	header;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		header.nb_lines = 0;
		return (header);
	}
	header = ft_readtitle(fd);
	if (header.nb_lines)
	{
		ft_readmap(fd, &header);
		close (fd);
		return (header);
	}
	close(fd);
	header.nb_lines = 0;
	return (header);
}
