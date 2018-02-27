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

static void			remove_file(char **files, int i)
{
	while (files[i])
	{
		ft_strdel(&files[i]);
		files[i] = ft_strdup(files[i + 1]);
		i++;
	}
}

void				parse_files(char **files, int n, t_ls *ls, char *path)
{
	struct stat		buf;
	int				i;
	int				count_removed;
	char 			*tmp;

	i = 0;
	tmp = NULL;
	count_removed = 0;
	while (files[i])
	{
		tmp = ft_strjoin(path, files[i]);
		if (lstat(tmp, &buf) == -1)
		{
			write(2, "ls: ", 4);
			perror(files[i]);
			remove_file(files, i);
			count_removed++;
		}
		else
			i++;
		ft_strdel(&tmp);
	}
	ls_sort(files, n - count_removed, ls, path);
	ft_ls_recursion(files, ls, path);
}
