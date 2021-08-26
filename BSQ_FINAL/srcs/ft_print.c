/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoiron <mpoiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:33:06 by mbennett          #+#    #+#             */
/*   Updated: 2021/08/24 13:33:55 by mpoiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/ft_file.h"

void	ft_putobstacle(t_header *head)
{
	t_list	*next_ptr;

	write (1, &head->obstacle, 1);
	next_ptr = head->first->next;
	free(head->first);
	head->first = next_ptr;
}

void	ft_putfull(t_header head, t_result res)
{
	int	i;

	i = 0;
	while (i < res.length + 1)
	{
		write (1, &head.full, 1);
		i++;
	}
}

void	ft_print(t_result res, t_header head)
{
	t_point	pt;

	pt.y = 0;
	while (pt.y < head.nb_lines)
	{
		pt.x = 0;
		while (pt.x < head.nb_col)
		{
			if (head.first && pt.x == head.first->point.x
				&& pt.y == head.first->point.y)
				ft_putobstacle(&head);
			else if (pt.x == res.point.x && pt.y >= res.point.y
				&& pt.y <= res.point.y + res.length)
			{
				ft_putfull(head, res);
				pt.x = pt.x + res.length;
			}
			else
				write (1, &head.empty, 1);
			pt.x++;
		}
		write (1, "\n", 1);
		pt.y++;
	}
}
