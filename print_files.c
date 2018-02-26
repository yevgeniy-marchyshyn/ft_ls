/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:52:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/22 12:52:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int				count_dirs(char **files, char *path)
{
	int			i;
	int			dirs;

	i = 0;
	dirs = 0;
	while (files[i])
	{
		if (is_dir(files[i], path))
			dirs++;
		i++;
	}
	return (dirs);
}

int						print_files(char **files, t_ls *ls, char *path)
{
	int			i;
	int			dirs;

	i = 0;
	dirs = count_dirs(files, path);
	while (files[i])
	{
		if (((!is_dir(files[i], path) && !link_to_dir(files[i], path)) ||
				ls->count_directories) && print_dot(files[i], ls))
		{
			ft_printf("%s\n", files[i]);
			ls->indents = 1;
		}
		i++;
	}
	return (dirs);
}
