/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timecmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 13:47:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/02 13:47:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		compare_time(time_t s1, time_t s2, long ns1, long ns2)
{
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

int				timecmp(char *file1, char *file2, char *path)
{
	t_stat			buf1;
	t_stat			buf2;
	char			*tmp1;
	char			*tmp2;

	if (!path)
		lstat(file1, &buf1);
	else
	{
		tmp1 = ft_strjoin(path, file1);
		lstat(tmp1, &buf1);
		ft_strdel(&tmp1);
	}
	if (!path)
		lstat(file2, &buf2);
	else
	{
		tmp2 = ft_strjoin(path, file2);
		lstat(tmp2, &buf2);
		ft_strdel(&tmp2);
	}
	return (compare_time(buf1.st_mtimespec.tv_sec, \
	buf2.st_mtimespec.tv_sec, \
	buf1.st_mtimespec.tv_nsec, \
	buf2.st_mtimespec.tv_nsec));
}
