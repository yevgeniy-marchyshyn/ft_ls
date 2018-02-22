/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:13:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/22 13:13:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				max_size_lst(t_list *head)
{
	struct stat		buf;
	t_list			*lst;
	int				max_length;

	max_length = 0;
	lst = head;
	while (lst != NULL)
	{
		lstat(lst->content, &buf);
		if (ft_itoa_len(buf.st_size) > max_length)
			max_length = ft_itoa_len(buf.st_size);
		lst = lst->next;
	}
	return (max_length);
}
