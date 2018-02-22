/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_len_group_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:25:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/22 15:25:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 		max_len_group_lst(t_list *head)
{
	struct stat		buf;
	struct group	*gr;
	int				max_length;
	t_list			*lst;
	int 			len;

	max_length = 0;
	lst = head;
	while (lst != NULL)
	{
		lstat(lst->content, &buf);
		gr = getgrgid(buf.st_gid);
		len = ft_strlen(gr->gr_name);
		if (len > max_length)
			max_length = len;
		lst = lst->next;
	}
	return (max_length);
}