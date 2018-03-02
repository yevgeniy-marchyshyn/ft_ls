/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:33:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/26 20:33:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_dir_continue(char **files, int n, t_ls *ls, char *path)
{
	int i;

	i = 0;
	ls_sort(files, n, ls, path);
	if (ls->include_dot)
		while (i < n)
			ft_printf("%s\n", files[i++]);
	else
	{
		while (i < n)
		{
			if (files[i][0] != '.')
				ft_printf("%s\n", files[i]);
			i++;
		}
	}
}

void			ls_dir(char *dirname, t_ls *ls, char *path)
{
	char			**files;
	int				n;

	path = ft_strjoin(dirname, "/");
	if ((n = ls_count_files(dirname, NULL)))
	{
		files = (char **)malloc(sizeof(char *) * (n + 1));
		files = ls_read_files(files, dirname);
		sort_ascii_bubble(files, n);
		if (ls->recursively)
			parse_files(files, n, ls, path);
		else if (ls->long_format)
		{
			ls_sort(files, n, ls, NULL);
			lf(files, ls, path);
		}
		else
			ls_dir_continue(files, n, ls, path);
		ft_strdel(&path);
		free_words(files);
	}
	ft_strdel(&path);
}
