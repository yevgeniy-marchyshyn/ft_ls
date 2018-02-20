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

static void		print_access(mode_t st_mode)
{
	char		*o;
	ssize_t 	value;
	int 		div;
	int 		i;

	o = ibs_uns(st_mode, 8);
	value = ft_atoi(o);
	value %= 1000;
	div = 100;
	i = 0;
	while (i != 3)
	{
		access_flag(value / div);
		value %= div;
		div /= 10;
		i++;
	}
	ft_strdel(&o);
}

static void		print_long_format(char *filename, int w1, int w2)
{
	struct stat		buf;
	struct passwd	*pw;
	struct group	*gr;
	char 			*time;

	lstat(filename, &buf);
	pw = getpwuid(buf.st_uid);
	gr = getgrgid(buf.st_gid);
	time = ctime(&buf.st_mtime);
	ft_printf("%c", define_type(&buf));
	print_access(buf.st_mode);
	ft_printf("  %*zu", w1 - ft_itoa_len(buf.st_nlink), buf.st_nlink);
	ft_printf("  %s", pw->pw_name);
	ft_printf("  %s", gr->gr_name);
	ft_printf("  %*zu", w2 - ft_itoa_len(buf.st_size), buf.st_size);
	ft_printf("  %s", );
	ft_printf("\n");
}

nlink_t 			lf_length_1(char **files, int n)
{
	struct stat		buf;
	int				i;
	nlink_t			max_length;

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

off_t				lf_length_2(char **files, int n)
{
	struct stat		buf;
	int				i;
	nlink_t			max_length;

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
	nlink_t		w1;
	off_t		w2;

	i = 0;
	w1 = lf_length_1(files, n);
	w2 = lf_length_2(files, n);
	ft_printf("total: %zu\n", ls_total(files, n, ls));
	while (i < n)
		print_long_format(files[i++], w1, w2);
}