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

void		ls_dir(char *dirname, t_ls *ls, char *path)
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
			long_format(files, ls, path);
		}
		else
			ls_dir_ext(files, n, ls);
	}
	ft_strdel(&path);
}
