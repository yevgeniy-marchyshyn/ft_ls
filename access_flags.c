/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 13:16:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/04 13:16:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			set_user_flags(char **access_flags, mode_t st_mode)
{
	if (st_mode & S_IRWXU && st_mode & S_ISUID)
	{
		(*access_flags)[0] = 'r';
		if (st_mode & S_IWUSR)
			(*access_flags)[1] = 'w';
		if (st_mode & S_ISUID && st_mode & S_IXUSR)
			(*access_flags)[2] = 's';
		else if (st_mode & S_ISUID && !(st_mode & S_IXUSR))
			(*access_flags)[2] = 'S';
		else
			(*access_flags)[2] = 'x';
	}
	else
	{
		if (st_mode & S_IRUSR)
			(*access_flags)[0] = 'r';
		if (st_mode & S_IWUSR)
			(*access_flags)[1] = 'w';
		if (st_mode & S_IXUSR)
			(*access_flags)[2] = 'x';
		else if (st_mode & S_ISUID && st_mode & S_IXUSR)
			(*access_flags)[2] = 's';
		else if (st_mode & S_ISUID && !(st_mode & S_IXUSR))
			(*access_flags)[2] = 'S';
	}
}

static void			set_group_flags(char **access_flags, mode_t st_mode)
{
	if (st_mode & S_IRWXG && st_mode & S_ISGID)
	{
		(*access_flags)[3] = 'r';
		if (st_mode & S_IWGRP)
			(*access_flags)[4] = 'w';
		if (st_mode & S_ISGID && st_mode & S_IXGRP)
			(*access_flags)[5] = 's';
		else if (st_mode & S_ISGID && !(st_mode & S_IXGRP))
			(*access_flags)[5] = 'S';
		else
			(*access_flags)[5] = 'x';
	}
	else
	{
		if (st_mode & S_IRGRP)
			(*access_flags)[3] = 'r';
		if (st_mode & S_IWGRP)
			(*access_flags)[4] = 'w';
		if (st_mode & S_IXGRP)
			(*access_flags)[5] = 'x';
		else if (st_mode & S_ISGID && st_mode & S_IXGRP)
			(*access_flags)[5] = 's';
		else if (st_mode & S_ISGID && !(st_mode & S_IXGRP))
			(*access_flags)[5] = 'S';
	}
}

static void			set_others_flags(char **access_flags, mode_t st_mode)
{
	if (st_mode & S_IRWXO && st_mode & S_ISVTX)
	{
		(*access_flags)[6] = 'r';
		if (st_mode & S_IWOTH)
			(*access_flags)[7] = 'w';
		if (st_mode & S_ISVTX && st_mode & S_IXOTH)
			(*access_flags)[8] = 't';
		else if (st_mode & S_ISVTX && !(st_mode & S_IXOTH))
			(*access_flags)[8] = 'T';
		else
			(*access_flags)[8] = 'x';
	}
	else
	{
		if (st_mode & S_IROTH)
			(*access_flags)[6] = 'r';
		if (st_mode & S_IWOTH)
			(*access_flags)[7] = 'w';
		if (st_mode & S_IXOTH)
			(*access_flags)[8] = 'x';
		else if (st_mode & S_ISVTX && st_mode & S_IXOTH)
			(*access_flags)[8] = 't';
		else if (st_mode & S_ISVTX && !(st_mode & S_IXOTH))
			(*access_flags)[8] = 'T';
	}
}

char				*access_flags(mode_t st_mode)
{
	char			*s;

	s = ft_strnew(9);
	ft_memset(s, '-', 9);
	set_user_flags(&s, st_mode);
	set_group_flags(&s, st_mode);
	set_others_flags(&s, st_mode);
	return (s);
}
