/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoiron <mpoiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:37:10 by mpoiron           #+#    #+#             */
/*   Updated: 2021/08/26 11:54:08 by mpoiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_list
{
	struct s_list	*next;
	t_point			point;
}					t_list;

typedef struct s_header
{
	int		nb_lines;
	int		nb_col;
	char	empty;
	char	obstacle;
	char	full;
	t_list	*first;
}				t_header;

typedef struct s_result
{
	t_point		point;
	int			length;
}				t_result;

void			ft_solve(int len, t_point pt, t_header head, t_result *res);
unsigned int	ft_atoi(char *str, char *str2);
void			set_point(t_point point, t_list **first);
t_header		ft_openfile(char *name);
t_header		ft_stdin(void);
int				ft_readline(int fd, t_header *header, int i, t_list	**first);
t_header		ft_readtitle(int fd);
void			ft_print(t_result res, t_header head);

#endif