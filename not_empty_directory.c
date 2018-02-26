/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_empty_directory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 00:35:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/25 00:35:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					not_empty_directory(char *dirname, t_ls *ls)
{
	DIR					*dir;
	struct dirent		*sd;
	int					n;

	n = 0;
	dir = opendir(dirname);
	if (dir == NULL)
	{
		perror(dirname);
		return (n);
	}
	if (dir)
	{
		while ((sd = readdir(dir)) != NULL)
		{
			if (print_dot(sd->d_name, ls))
				n++;
		}
	}
	closedir(dir);
	return (n);
}
