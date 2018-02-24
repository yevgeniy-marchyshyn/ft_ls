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
	int 			i;
	int 			count_removed;

	i = 0;
	count_removed = 0;
	while (files[i])
	{
		if (lstat(ft_strjoin(path, files[i]), &buf) == -1)
		{
			write(2, "ft_ls: ", 7);
			perror(files[i]);
			remove_file(files, i);
			count_removed++;
		}
		else
			i++;
	}
	ls_sort(files, n - count_removed, ls);
	ft_ls_recursion(files, ls, path);
}