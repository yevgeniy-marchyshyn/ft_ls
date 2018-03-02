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

//static int			timecmp(char *file1, char *file2, char *path)
//{
//	t_stat			buf1;
//	t_stat			buf2;
//	char 			*tmp1;
//	char 			*tmp2;
//
//	if (!path)
//		lstat(file1, &buf1);
//	else
//	{
//		tmp1 = ft_strjoin(path, file1);
//		lstat(tmp1, &buf1);
//		ft_strdel(&tmp1);
//	}
//	if (!path)
//		lstat(file2, &buf2);
//	else
//	{
//		tmp2 = ft_strjoin(path, file2);
//		lstat(tmp2, &buf2);
//		ft_strdel(&tmp2);
//	}
//	return (compare_time(buf1.st_mtimespec.tv_sec,
//						 buf2.st_mtimespec.tv_sec,
//						 buf1.st_mtimespec.tv_nsec,
//						 buf2.st_mtimespec.tv_nsec));
//	if (buf1.st_mtimespec.tv_sec > buf2.st_mtimespec.tv_sec)
//		return (2);
//	else
//	{
//		if (buf1.st_mtimespec.tv_sec == buf2.st_mtimespec.tv_sec)
//		{
//			if (buf1.st_mtimespec.tv_nsec > buf2.st_mtimespec.tv_nsec)
//				return (2);
//			return (buf1.st_mtimespec.tv_nsec > buf2.st_mtimespec.tv_nsec) ? 1 : 0);
//		}
//		return (0);
//	}
//}

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

static void			sort_mtime_rev(char **files, int n, char *path)
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

	i = 0;
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