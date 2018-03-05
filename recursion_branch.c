/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_branch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:52:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/01 14:52:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_dir_continue(t_ls *ls, char **files, char *path, int n)
{
	int i;

	i = 0;
	if (!ls->not_sort)
		sort_ascii_bubble(files, n);
	if (ls->recursion)
		parse_files(files, n, ls, path);
	else
	{
		ls_sort(files, n, ls, path);
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

	files = NULL;
	tmp1 = ft_strjoin(path, dirname);
	tmp2 = ft_strjoin(tmp1, "/");
	ft_strdel(&tmp1);
	if ((n = ls_count_files(dirname, tmp2)))
	{
		files = (char **)malloc(sizeof(char *) * (n + 1));
		files = ls_read_files(files, tmp2);
		ls_dir_continue(ls, files, tmp2, n);
		free_words(files);
	}
	ft_strdel(&tmp2);
}

static void		recursion_continue(char **files, t_ls *ls, char *path)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (files[i])
	{
		tmp = ft_strjoin(path, files[i]);
		if (is_dir(tmp, NULL))
		{
			if ((print_dot(files[i], ls) || ls->not_sort ||\
			(ls->skip_dots && skip_dots(files[i]))) && skip_dots(files[i]))
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

void			recursion_branch(char **files, t_ls *ls, char *path)
{
	ls->handled_args = 1;
	if (ls->long_format)
		lf(files, ls, path);
	else
		print_files(files, ls, path);
	recursion_continue(files, ls, path);
}
