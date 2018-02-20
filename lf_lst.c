/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:41:40 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/20 14:41:43 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_access(mode_t st_mode)
{
	ft_printf("st_mode: %zd\n", st_mode);
}

static void		print_long_format(t_list *lst)
{
	struct stat		buf;

	stat(lst->content, &buf);
	print_access(buf.st_mode);
}

void			lf_lst(t_list *head)
{
	t_list *lst;

	lst = head;
	ft_printf("total: %zu\n", ls_total_lst(head));
	while (lst != NULL)
	{
		print_long_format(lst->content);
		lst = lst->next;
	}
}
