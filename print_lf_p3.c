/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lf_p3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:06:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/05 15:06:00 by xlogin           ###   ########.fr       */
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

void			print_lf_p3(char *path, char *f, char *tmp, t_stat *buf)
{
	if (define_type(buf) == 'l')
		is_link(path, f, tmp);
	else
		ft_printf("%-s\n", f);
}
