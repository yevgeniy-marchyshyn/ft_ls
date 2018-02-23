/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_total_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:35:27 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/20 14:37:24 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_total_lst(t_list *head, t_ls *ls, char *path)
{
	struct stat		buf;
	t_list			*lst;
	int				sum;

	sum = 0;
	lst = head;
	while (lst != NULL)
	{
		if (print_dot(lst->content, ls))
		{
			lstat(ft_strjoin(path, lst->content), &buf);
			sum += buf.st_blocks;
		}
		lst = lst->next;
	}
	return (sum);
}
