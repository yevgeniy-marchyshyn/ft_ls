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

void			lf_print_files(t_list *head, t_ls *ls, char *path)
{
	t_list	*lst;
	int 	w[4];

	lst = head;
	w[0] = max_links_lst(head);
	w[1] = max_len_user_lst(head);
	w[2] = max_len_group_lst(head);
	w[3] = max_size_lst(head);
	while (lst != NULL)
	{
		if ((lst->content_size != 'd' || ls->recursively) &&
				print_dot(lst->content, ls))
		{
			print_long_format(lst->content, w, path);
			ls->indents = 1;
		}
		lst = lst->next;
	}
}
