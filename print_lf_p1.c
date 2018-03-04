/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lf_p1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:53:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/04 12:53:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 		print_lf_p1(t_stat *buf, char *path)
{
	char		type;
	ssize_t 	res;
	char 		*flags;
	char		attr[1024];

	type = define_type(buf);
	ft_printf("%c", type);
	flags = access_flags(buf->st_mode);
	res = listxattr(path, attr, sizeof(attr), XATTR_NOFOLLOW);
	ft_printf("%s", flags);
	if (res > 0)
		ft_printf("@");
	else
		ft_printf(" ");
	ft_strdel(&flags);
	return (1);
}
