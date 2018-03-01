/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_read_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:35:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/26 20:35:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**ls_read_files(char **files, char *dirname)
{
	DIR					*dir;
	struct dirent		*sd;
	int					i;

	i = 0;
	dir = opendir(dirname);
	while ((sd = readdir(dir)) != NULL)
		files[i++] = ft_strdup(sd->d_name);
	files[i] = NULL;
	closedir(dir);
	return (files);
}
