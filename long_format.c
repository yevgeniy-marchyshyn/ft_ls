/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:30:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/20 13:30:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//static void		print_access(mode_t st_mode)
//{
//	char		*o;
//	ssize_t 	value;
//	int 		div;
//	int 		i;
//
//	o = ibs_uns(st_mode, 8);
//	value = ft_atoi(o);
//	value %= 1000;
//	div = 100;
//	i = 0;
//	while (i != 3)
//	{
//		access_flag(value / div);
//		value %= div;
//		div /= 10;
//		i++;
//	}
//	ft_strdel(&o);
//}

//static char 	*time_format(time_t n)
//{
//	char *time;
//	char *time_format;
//
//	time = ctime(&n);
//	time_format = ft_strsub(time, 4, 12);
//	return (time_format);
//}

//static char		*linkpath(char *filename)
//{
//	char	*buff;
//
//	buff = ft_strnew(128);
//	readlink(filename, buff, 127);
//	return (buff);
//}

//static void		print_long_format(char *filename, int w1, int w2)
//{
//	struct stat		buf;
//	struct passwd	*pw;
//	struct group	*gr;
//	char 			*link_path;
//
//	lstat(filename, &buf);
//	pw = getpwuid(buf.st_uid);
//	gr = getgrgid(buf.st_gid);
//	ft_printf("%c", define_type(&buf));
//	print_access(buf.st_mode);
//	ft_printf(" %*zu", w1 + 1, buf.st_nlink);
//	ft_printf(" %s", pw->pw_name);
//	ft_printf("  %s", gr->gr_name);
//	ft_printf(" %*zu", w2 + 1, buf.st_size);
//	ft_printf(" %s", time_format(buf.st_mtime));
//	if (define_type(&buf) == 'l')
//	{
//		link_path = linkpath(filename);
//		ft_printf(" %s -> %s\n", filename, link_path);
//		ft_strdel(&link_path);
//	}
//	else
//		ft_printf(" %s\n", filename);
//
//}

int 			lf_length_1(char **files, int n)
{
	struct stat		buf;
	int				i;
	int				max_length;

	i = 0;
	max_length = 0;
	while (i < n)
	{
		lstat(files[i++], &buf);
		if (ft_itoa_len(buf.st_nlink) > max_length)
			max_length = ft_itoa_len(buf.st_nlink);
	}
	return (max_length);
}

int				lf_length_2(char **files, int n)
{
	struct stat		buf;
	int				i;
	int				max_length;

	i = 0;
	max_length = 0;
	while (i < n)
	{
		lstat(files[i++], &buf);
		if (ft_itoa_len(buf.st_size) > max_length)
			max_length = ft_itoa_len(buf.st_size);
	}
	return (max_length);
}

void				long_format(char **files, int n, t_ls *ls)
{
	int			i;
	int			w1;
	int			w2;

	i = 0;
	w1 = lf_length_1(files, n);
	w2 = lf_length_2(files, n);
	ft_printf("total %lld\n", ls_total(files, n, ls));
	while (i < n)
	{
		if (print_dot(files[i], ls))
			print_long_format(files[i], w1, w2);
		i++;
	}
}