/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 18:29:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/18 18:29:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				parse_files(char **files, t_ls *ls, char *path)
{
	struct stat		buf;
	t_list			*head;
	t_list			*elem;
	int 			i;

	i = 0;
	head = NULL;
	while (files[i])
	{
		if (lstat(ft_strjoin(path, files[i]), &buf) == -1)
		{
			write(2, "ft_ls: ", 7);
			perror(files[i]);
		}
		else
		{
			elem = ft_lstnew(files[i], (size_t)define_type(&buf));
			ft_lst_push_back(&head, elem);
		}
		i++;
	}
	ft_ls_recursion(head, ls, path);
}