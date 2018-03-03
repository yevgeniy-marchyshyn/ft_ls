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

static void					print_not_dirs(char **files, t_ls *ls, char *path)
{
	int		i;

	i = 0;
	while (files[i])
	{
		if (!is_dir(files[i], path) && !link_to_dir(files[i], path))
		{
			ft_printf("%s\n", files[i]);
			ls->new_line = 1;
		}
		i++;
	}
	ls->handled_args = 1;
}

static int 					count_dirs(char **files, char *path)
{
	int i;
	int dirs;

	i = 0;
	dirs = 0;
	while (files[i])
	{
		if (is_dir(files[i], path) || link_to_dir(files[i], path))
			dirs++;
		i++;
	}
	return (dirs);
}

void						print_files(char **files, t_ls *ls, char *path)
{
	int			i;

	i = 0;
	if (!ls->handled_args)
	{
		print_not_dirs(files, ls, path);
		if (count_dirs(files, path) > 1)
			ls->dirs = 1;
		return ;
	}
	while (files[i])
	{
		if (print_dot(files[i], ls))
			ft_printf("%s\n", files[i]);
		i++;
	}
}
