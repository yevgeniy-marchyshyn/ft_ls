/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:05:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/21 18:05:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_long_format(char *filename, int *w, char *path)
{
	struct stat		buf;
	struct passwd	*pw;
	struct group	*gr;
	char 			*link_path;
	char 			*path2;
	char 			*path3;

	if (path != NULL)
	{
		path2 = ft_strjoin(path, "/");
		path3 = ft_strjoin(path2, filename);
		lstat(path3, &buf);
	}
	else
		lstat(filename, &buf);
	pw = getpwuid(buf.st_uid);
	gr = getgrgid(buf.st_gid);
	ft_printf("%c", define_type(&buf));
	print_access(buf.st_mode);
	ft_printf(" %*zu", w[0] + 1, buf.st_nlink);
	ft_printf(" %-*s ", w[1] + 1, pw->pw_name);
	ft_printf(" %*s ", w[2] + 1, gr->gr_name);
	ft_printf("%*zu", w[3] + 1, buf.st_size);
	ft_printf(" %s", time_format(buf.st_mtime));
	if (define_type(&buf) == 'l')
	{
		link_path = linkpath(path ? path3 : filename);
		ft_printf(" %s -> %s\n", filename, link_path);
		ft_strdel(&link_path);
	}
	else
		ft_printf(" %s\n", filename);
}
