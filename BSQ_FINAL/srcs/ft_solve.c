/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoiron <mpoiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:59:57 by mpoiron           #+#    #+#             */
/*   Updated: 2021/08/26 11:45:05 by mpoiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_file.h"
#include <stdlib.h>

t_header	ft_find_next(t_point pt, t_header h)
{
	while (h.first && !(h.first->point.y >= pt.y && h.first->point.x > pt.x))
		h.first = h.first->next;
	return (h);
}

int	ft_check_line(int len, t_point pt, t_header h)
{
	if (pt.y + len > h.nb_lines - 1)
		return (0);
	else if (pt.x + len > h.nb_col - 1)
		return (0);
	return (1);
}

int	ft_check_square(int len, t_point *pt, t_header *h)
{
	t_list		*ptr;

	ptr = h->first;
	while (ptr && !(ptr->point.y >= pt->y + len && ptr->point.x > pt->x + len))
	{
		if (ptr->point.x >= pt->x && ptr->point.x <= pt->x + len)
		{
			if (ptr->point.y <= pt->y + len)
			{
				pt->x = ptr->point.x + 1;
				if (ptr->point.y == pt->y)
					h->first = ptr;
				ptr = NULL;
				return (0);
			}
		}
		ptr = ptr->next;
	}
	ptr = NULL;
	return (1);
}

void	ft_solve_line(int *len, t_point pt, t_header head, t_result *res)
{
	if (ft_check_line(*len, pt, head))
	{
		if (ft_check_square(*len, &pt, &head))
		{
			res->point = pt;
			res->length = *len;
			*len = *len + 1;
			ft_solve_line(len, pt, head, res);
		}
		else
			ft_solve_line(len, pt, head, res);
	}
}

void	ft_solve(int len, t_point pt, t_header head, t_result *res)
{
	if (pt.y + len <= head.nb_lines - 1)
	{
		pt.x = 0;
		ft_solve_line(&len, pt, head, res);
		pt.y = pt.y + 1;
		ft_solve(len, pt, ft_find_next(pt, head), res);
	}
}
