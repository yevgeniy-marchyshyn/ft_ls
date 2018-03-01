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

static void		device_number(t_stat *buf)
{
	ft_printf("%lld", buf->st_rdev >> 24 & 0xff);
	ft_printf(",    ");
	ft_printf("%lld", buf->st_rdev & 0xffffff);
	ft_printf(" ");
}

static void 	print_time(time_t n)
{
	time_t 		current_time;
	char		*ctime_format;
	char		*mtime;
	char 		*end_of_line;
	char 		*year;

	ctime_format = ctime(&n);
	if ((end_of_line = ft_strchr(ctime_format, '\n')))
		*end_of_line = '\0';
	current_time = time(NULL);
	year = NULL;
	mtime = NULL;
	if (ABS(current_time - n) > 15778463)
	{
		mtime = ft_strsub(ctime_format, 4, 7);
		year = ft_strsub(ctime_format, 20, 23);
		ft_printf(" %s ", mtime);
		ft_printf("%s ", year);
	}
	else
	{
		mtime = ft_strsub(ctime_format, 4, 12);
		ft_printf(" %s ", mtime);
	}
	ft_strdel(&mtime);
	year ? ft_strdel(&year) : 0;
}

static void		print_lf_continue(t_stat *buf, t_pw *pw, t_group *gr, int *w)
{
	char type;

	type = define_type(buf);
	ft_printf("%c", type);
	print_access(buf->st_mode);
	ft_printf(" %*zu", w[0] + 1, buf->st_nlink);
	ft_printf(" %-*s ", w[1] + 1, pw->pw_name);
	ft_printf("%-*s ", w[2] + 1, gr->gr_name);
	if (type == 'c' || type == 'b')
		device_number(buf);
	else
		ft_printf("%*zu", w[3], buf->st_size);
	print_time(buf->st_mtime);
}

static void		if_it_is_a_link(char *path, char *filename, char *tmp2)
{
	char *link_path;

	link_path = linkpath(path ? tmp2 : filename);
	ft_printf("%s -> %s\n", filename, link_path);
	ft_strdel(&link_path);
}

void			print_lf(char *filename, int *w, char *path)
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
	print_lf_continue(&buf, pw, gr, w);
	if (define_type(&buf) == 'l')
		if_it_is_a_link(path, filename, tmp2);
	else
		ft_printf("%s\n", filename);
	ft_strdel(&tmp2);
}
