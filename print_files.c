/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:52:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/22 12:52:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_files(t_list *head, t_ls *ls)
{
	t_list *lst;

	lst = head;
	while (lst != NULL)
	{
		if (lst->content_size != 'd')
		{
			ft_printf("%s\n", lst->content);
			ls->indents = 1;
		}
		lst = lst->next;
	}
}
