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

quad_t		ls_total_lst(t_list *head)
{
	struct stat		buf;
	t_list			*lst;
	quad_t			sum;

	sum = 0;
	lst = head;
	while (lst != NULL)
	{
		stat(lst->content, &buf);
		ft_printf("block: %zu", buf.st_blocks);
		sum += buf.st_blocks;
		lst = lst->next;
	}
	return (sum);
}
