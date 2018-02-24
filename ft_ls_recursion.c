/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marchyshyn <ymarchys@student.unit.ua>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 22:26:23 by marchyshy         #+#    #+#             */
/*   Updated: 2018/02/18 22:26:40 by marchyshy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		**ls_fill_files(char **files, char *path)
{
	DIR					*dir;
	struct dirent		*sd;
	int 				i;

	i = 0;
	dir = opendir(path);
	while ((sd = readdir(dir)) != NULL)
		files[i++] = ft_strdup(sd->d_name);
	files[i] = NULL;
	closedir(dir);
	return (files);
}

static void		ls_dir_ext(t_ls *ls, char **files, char *path3, int n)
{
	int i;

	i = 0;
	sort_ascii_bubble(files, n);
	if (ls->recursively)
		parse_files(files, n, ls, path3);
	else
	{
		ls_sort(files, n, ls);
		i = 0;
		while (i < n)
			ft_printf("%s\n", files[i++]);
	}
}

static void		ls_dir(char *dirname, t_ls *ls, char *path)
{
	char			**files;
	char 			*path2;
	char 			*path3;
	int				n;

	path2 = ft_strjoin(path, dirname);
	path3 = ft_strjoin(path2, "/");
	if ((n = ls_count_files(dirname, path3)))
	{
		files = (char **)malloc(sizeof(char *) * (n + 1));
		files = ls_fill_files(files, path3);
		ls_dir_ext(ls, files, path3, n);
	}
}

void			ft_ls_recursion(char **files, t_ls *ls, char *path)
{
	int 	i;

	i = 0;
	if (ls->long_format)
		long_format(files, ls, path);
	else
		print_files(files, ls);
	while (files[i])
	{
		if (is_dir(ft_strjoin(path, files[i])))
		{
			if (print_dot(files[i], ls) && skip_dots(files[i]))
			{
				ft_printf("\n%s%s:\n", path, files[i]);
				ls_dir(files[i], ls, path);
			}
		}
		i++;
	}
}
