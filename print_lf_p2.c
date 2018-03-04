/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lf_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 13:05:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/04 13:05:00 by xlogin           ###   ########.fr       */
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

void	print_lf_p2(t_stat *buf, t_pw *pw, t_group *gr, int *w)
{
	char type;

	type = define_type(buf);
	ft_printf(" %*zu", w[0], buf->st_nlink);
	ft_printf(" %-*s ", w[1], pw->pw_name);
	ft_printf(" %-*s ", w[2], gr->gr_name);
	if (type == 'c' || type == 'b')
		device_number(buf);
	else
		ft_printf(" %*zu", w[3], buf->st_size);
	print_time(buf->st_mtime);
}
