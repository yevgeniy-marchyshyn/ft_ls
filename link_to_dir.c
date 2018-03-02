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
	t_stat			buf;
	char			type;
	char			*tmp;

	tmp = NULL;
	if (!path)
		lstat(filename, &buf);
	else
	{
		tmp = ft_strjoin(path, filename);
		lstat(tmp, &buf);
	}
	type = define_type(&buf);
	if (type == 'l')
	{
		if (path)
			stat(tmp, &buf);
		else
			stat(filename, &buf);
		type = define_type(&buf);
		tmp ? ft_strdel(&tmp) : 0;
		return (type == 'd' ? 1 : 0);
	}
	tmp ? ft_strdel(&tmp) : 0;
	return (0);
}
