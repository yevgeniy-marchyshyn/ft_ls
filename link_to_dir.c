/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_to_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:58:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/26 19:58:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					link_to_dir(char *filename, char *path)
{
	struct stat		buf;
	char			type;
	char			*tmp;

	if (!path)
		lstat(filename, &buf);
	else
	{
		tmp = ft_strjoin(path, filename);
		lstat(tmp, &buf);
		ft_strdel(&tmp);
	}
	type = define_type(&buf);
	if (type == 'l')
	{
		stat(path ? tmp : filename, &buf);
		type = define_type(&buf);
		return (type == 'd' ? 1 : 0);
	}
	return (0);
}
