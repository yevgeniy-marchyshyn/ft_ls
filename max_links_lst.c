/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_links_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:11:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/22 13:11:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 			max_links_lst(t_list *head, char *path)
{
	struct stat		buf;
	t_list			*lst;
	int				max_length;

	max_length = 0;
	lst = head;
	while (lst != NULL)
	{
		if (path == NULL)
			lstat(lst->content, &buf);
		else
			lstat(ft_strjoin(path, lst->content), &buf);
		if (ft_itoa_len(buf.st_nlink) > max_length)
			max_length = ft_itoa_len(buf.st_nlink);
		lst = lst->next;
	}
	return (max_length);
}
