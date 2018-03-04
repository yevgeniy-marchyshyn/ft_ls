/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 21:39:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/01 21:39:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		is_link(char *path, char *filename, char *tmp2)
{
	char *link_path;

	link_path = linkpath(path ? tmp2 : filename);
	ft_printf("%s -> %s\n", filename, link_path);
	ft_strdel(&link_path);
}

void			print_lf(char *filename, int *w, char *path, t_ls *ls)
{
	t_stat		buf;
	t_pw		*pw;
	t_group		*gr;
	char		*tmp1;
	char		*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	if (path != NULL)
	{
		tmp1 = ft_strjoin(path, "/");
		tmp2 = ft_strjoin(tmp1, filename);
		ft_strdel(&tmp1);
		lstat(tmp2, &buf);
	}
	else
		lstat(filename, &buf);
	if (!(pw = getpwuid(buf.st_uid)) || !(gr = getgrgid(buf.st_gid)))
		return ;
	tmp2 ? print_lf_p1(&buf, tmp2) : print_lf_p1(&buf, filename);
	print_lf_p2(&buf, pw, gr, w);
	if (define_type(&buf) == 'l')
		is_link(path, filename, tmp2);
	else
		ft_printf("%-s\n", filename);
	if (ls->attr)
		tmp2 ? print_lf_p3(tmp2) : print_lf_p3(filename);
	ft_strdel(&tmp2);
}
