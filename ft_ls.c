/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:29:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/16 19:29:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ls(char **files, t_ls *ls)
{
	char		*path;
	int			i;

	i = 0;
	path = NULL;
	if (ls->argc)
	{
		if (ls->long_format)
			lf_not_dirs(files, ls, path);
		else
			print_files(files, ls, path);
	}
	while (files[i])
	{
		if (is_dir(files[i], path) || link_to_dir(files[i], path))
		{
			if (ls->new_line)
				ft_printf("\n");
			if (ls->dirs || ls->error)
				ft_printf("%s:\n", files[i]);
			ls->new_line = 1;
			if (is_dir(files[i], path))
				ls_dir(files[i], ls, path);
			else if (link_to_dir(files[i], path) && !ls->long_format)
				ls_link(files[i], ls, path);
		}
		i++;
	}
}
