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

void		print_long_format(char *filename, int w1, int w2)
{
	struct stat		buf;
	struct passwd	*pw;
	struct group	*gr;
	char 			*link_path;

	lstat(filename, &buf);
	pw = getpwuid(buf.st_uid);
	gr = getgrgid(buf.st_gid);
	ft_printf("%c", define_type(&buf));
	print_access(buf.st_mode);
	ft_printf(" %*zu", w1 + 1, buf.st_nlink);
	ft_printf(" %s", pw->pw_name);
	ft_printf("  %s", gr->gr_name);
	ft_printf(" %*zu", w2 + 1, buf.st_size);
	ft_printf(" %s", time_format(buf.st_mtime));
	if (define_type(&buf) == 'l')
	{
		link_path = linkpath(filename);
		ft_printf(" %s -> %s\n", filename, link_path);
		ft_strdel(&link_path);
	}
	else
		ft_printf(" %s\n", filename);

}
