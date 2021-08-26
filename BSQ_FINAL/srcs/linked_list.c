/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoiron <mpoiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:10:34 by mpoiron           #+#    #+#             */
/*   Updated: 2021/08/24 10:11:44 by mpoiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_file.h"
#include <stdlib.h>

void	set_point(t_point point, t_list **first)
{
	t_list	*new;
	t_list	*current;

	new = malloc(sizeof(*new));
	new->point = point;
	new->next = NULL;
	current = *first;
	if (new)
	{
		if (current == NULL)
			*first = new;
		else
		{
			while (current->next != 0)
				current = current->next;
			current->next = new;
		}
	}
}
