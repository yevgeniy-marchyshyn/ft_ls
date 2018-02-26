/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:21:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/26 20:21:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_link(char *linkname, t_ls *ls, char *path)
{
	char		*link_path;
	char		*tmp;

	if (path)
	{
		tmp = ft_strjoin(path, linkname);
		link_path = linkpath(tmp);
		ft_strdel(&tmp);
	}
	else
		link_path = linkpath(linkname);
	ls_dir(link_path, ls, NULL);
}
