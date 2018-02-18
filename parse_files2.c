/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:54:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/18 15:54:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		parse_files2(char *dirname, char **files, t_opt *opt)
{
	struct stat		buf;
	t_list			*head;
	t_list			*elem;
	int 			k;
	char 			*path;

	head = NULL;
	k = 0;
	path = ft_strjoin(dirname, "/");
	ft_printf("path: %s\n", path);
	while (files[k])
	{
		if (lstat(ft_strjoin(path, files[k]), &buf) == -1)
		{
			write(2, "ft_ls: ", 7);
			perror(files[k]);
		}
		else
		{
			if (ft_strcmp(files[k], ".") != 0 && ft_strcmp(files[k], "..") != 0 && files[k][0] != '.')
			{
				elem = ft_lstnew(files[k], define_type(&buf));
				ft_lst_push_back(&head, elem);
			}
		}
		k++;
	}
	ft_ls(head, opt);
}
