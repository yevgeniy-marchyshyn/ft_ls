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

static int			timecmp(char *file1, char *file2)
{
	struct stat		buf;
	time_t			s1;
	time_t			s2;
	long			ns1;
	long			ns2;

	stat(file1, &buf);
	s1 = buf.st_mtimespec.tv_sec;
	ns1 = buf.st_mtimespec.tv_nsec;
	stat(file2, &buf);
	s2 = buf.st_mtimespec.tv_sec;
	ns2 = buf.st_mtimespec.tv_nsec;
	if (s1 > s2)
		return (2);
	else
	{
		if (s1 == s2)
		{
			if (ns1 > ns2)
				return (2);
			return (ns1 == ns2 ? 1 : 0);
		}
		return (0);
	}
}

static void		sort_rev(char **file, int n)
{
	char 	*tmp;
	int		i;
	int 	k;

	i = 0;
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

static void			sort_mtime_rev(char **files, int n)
{
	char 	*tmp;
	int		i;
	int 	k;

	i = 0;
	k = 0;
	while (k < n - 1)
	{
		i = 0;
		while (files[i])
		{
			if (files[i + 1] && timecmp(files[i], files[i + 1]) > 1)
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

static void			sort_mtime(char **files, int n)
{
	char 	*tmp;
	int		i;
	int 	k;

	i = 0;
	k = 0;
	while (k < n - 1)
	{
		i = 0;
		while (files[i])
		{
			if (files[i + 1] && !timecmp(files[i], files[i + 1]))
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

void				ls_sort(char **files, int n, t_ls *ls)
{
	if (ls->rev_lexic && !ls->sort_mtime)
		sort_rev(files, n);
	else if (ls->sort_mtime && !ls->rev_lexic)
		sort_mtime(files, n);
	else if (ls->sort_mtime && ls->rev_lexic)
	{
		sort_rev(files, n);
		sort_mtime_rev(files, n);
	}
}