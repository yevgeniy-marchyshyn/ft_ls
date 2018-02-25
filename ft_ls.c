/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:29:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/16 19:29:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		**ls_read_files(char **files, char *dirname)
{
	DIR					*dir;
	struct dirent		*sd;
	int 				i;

	i = 0;
	dir = opendir(dirname);
	while ((sd = readdir(dir)) != NULL)
	{
		files[i] = ft_strdup(sd->d_name);
		i++;
	}
	files[i] = NULL;
	closedir(dir);
	return (files);
}

static void		ls_dir_ext(char **files, int n, t_ls *ls)
{
	int i;

	i = 0;
	ls_sort(files, n, ls, NULL);
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

static void		ls_dir(char *dirname, t_ls *ls, char *path)
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
}

void			ft_ls(char **files, t_ls *ls)
{
	char 	*path;
	int 	i;

	path = NULL;
	i = 0;
	if (!ls->long_format)
		print_files(files, ls);
	else
		ls->indents = long_format_not_dirs(files, ls, path);
	while (files[i])
	{
		if (is_dir(files[i]))
		{
			if (ls->indents)
				ft_printf("\n");
			if (ls->first_directory || ls->indents)
				ft_printf("%s:\n", files[i]);
			ls->first_directory = 1;
			ls_dir(files[i], ls, path);
		}
		i++;
	}
}
