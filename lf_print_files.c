/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_print_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:55:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/22 12:55:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			lf_print_files(t_list *head, t_ls *ls)
{
	t_list	*lst;
	int 	w1;
	int 	w2;

	lst = head;
	w1 = max_links_lst(head);
	w2 = max_size_lst(head);
	while (lst != NULL)
	{
		if (lst->content_size != 'd')
		{
			print_long_format(lst->content, w1, w2);
			ls->indents = 1;
		}
		lst = lst->next;
	}
}
