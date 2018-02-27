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

static char		**ls_read_files_recursion(char **files, char *path)
{
	DIR					*dir;
	struct dirent		*sd;
	int					i;

	i = 0;
	dir = opendir(path);
	while ((sd = readdir(dir)) != NULL)
		files[i++] = ft_strdup(sd->d_name);
	files[i] = NULL;
	closedir(dir);
	return (files);
}

static void		ls_dir_ext_recurs(t_ls *ls, char **files, char *path3, int n)
{
	int i;

	i = 0;
	sort_ascii_bubble(files, n);
	if (ls->recursively)
		parse_files(files, n, ls, path3);
	else
	{
		ls_sort(files, n, ls, path3);
		i = 0;
		while (i < n)
			ft_printf("%s\n", files[i++]);
	}
}

static void		ls_dir_recursion(char *dirname, t_ls *ls, char *path)
{
	char			**files;
	char			*tmp1;
	char			*tmp2;
	int				n;

	tmp1 = ft_strjoin(path, dirname);
	tmp2 = ft_strjoin(tmp1, "/");
	ft_strdel(&tmp1);
	if ((n = ls_count_files(dirname, tmp2)))
	{
		files = (char **)malloc(sizeof(char *) * (n + 1));
		files = ls_read_files_recursion(files, tmp2);
		ls_dir_ext_recurs(ls, files, tmp2, n);
	}
	ft_strdel(&tmp2);
}

void			ft_ls_recursion(char **files, t_ls *ls, char *path)
{
	int		i;
	char 	*tmp;

	i = 0;
	tmp = NULL;
	if (ls->long_format)
		long_format(files, ls, path);
	else
		print_files(files, ls, path);
	while (files[i])
	{
		tmp = ft_strjoin(path, files[i]);
		if (is_dir(tmp, NULL))
		{
			if (print_dot(files[i], ls) && skip_dots(files[i]))
			{
				ft_printf("\n%s%s:\n", path, files[i]);
				ls_dir_recursion(files[i], ls, path);
			}
		}
		if (tmp != NULL)
			ft_strdel(&tmp);
		i++;
	}
}
