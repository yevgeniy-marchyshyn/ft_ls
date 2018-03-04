/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:19:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/19 16:19:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		sort_rev(char **file, int n)
{
	char 	*tmp;
	int		i;
	int 	k;

	k = 0;
	while (k < n - 1)
	{
		i = 0;
		while (file[i])
		{
			if (file[i + 1] && ft_strcmp(file[i], file[i + 1]) < 0)
			{
				tmp = file[i];
				file[i] = file[i + 1];
				file[i + 1] = tmp;
			}
			i++;
		}
		k++;
	}
}

static void			sort_mtime_rev(char **files, int n, char *path)
{
	char 	*tmp;
	int		i;
	int 	k;

	k = 0;
	while (k < n - 1)
	{
		i = 0;
		while (files[i])
		{
			if (files[i + 1] && timecmp(files[i], files[i + 1], path) > 1)
			{
				tmp = files[i];
				files[i] = files[i + 1];
				files[i + 1] = tmp;
			}
			i++;
		}
		k++;
	}
}

static void			sort_mtime(char **files, int n, char *path)
{
	char 	*tmp;
	int		i;
	int 	k;

	k = 0;
	while (k < n - 1)
	{
		i = 0;
		while (files[i])
		{
			if (files[i + 1] && !timecmp(files[i], files[i + 1], path))
			{
				tmp = files[i];
				files[i] = files[i + 1];
				files[i + 1] = tmp;
			}
			i++;
		}
		k++;
	}
}

void				ls_sort(char **files, int n, t_ls *ls, char *path)
{
	if (ls->not_sort == 0)
	{
		if (ls->rev_lexic && !ls->sort_mtime)
			sort_rev(files, n);
		else if (ls->sort_mtime && !ls->rev_lexic)
			sort_mtime(files, n, path);
		else if (ls->sort_mtime && ls->rev_lexic)
		{
			sort_rev(files, n);
			sort_mtime_rev(files, n, path);
		}
	}
}