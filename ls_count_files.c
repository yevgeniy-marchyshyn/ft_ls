/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_count_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 00:17:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/25 00:17:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_count_files(char *dirname, char *path)
{
	DIR					*dir;
	t_dir				*sd;
	int					n;

	n = 0;
	if (path == NULL)
		dir = opendir(dirname);
	else
		dir = opendir(path);
	if (dir == NULL)
	{
		perror(dirname);
		return (n);
	}
	if (dir)
		while ((sd = readdir(dir)) != NULL)
			n++;
	closedir(dir);
	return (n);
}
