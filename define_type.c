/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:32:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/16 19:32:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		define_type(t_stat *buf)
{
	if ((buf->st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	else if ((buf->st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((buf->st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((buf->st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((buf->st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((buf->st_mode & S_IFMT) == S_IFSOCK)
		return ('s');
	else
		return ('-');
}
