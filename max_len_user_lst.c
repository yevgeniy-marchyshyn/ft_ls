/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_len_user_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:16:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/22 15:16:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 		max_len_user_lst(t_list *head)
{
	struct stat		buf;
	struct passwd	*pw;
	int				max_length;
	t_list			*lst;
	int 			len;

	max_length = 0;
	lst = head;
	while (lst != NULL)
	{
		lstat(lst->content, &buf);
		pw = getpwuid(buf.st_uid);
		len = ft_strlen(pw->pw_name);
		if (len > max_length)
			max_length = len;
		lst = lst->next;
	}
	return (max_length);
}