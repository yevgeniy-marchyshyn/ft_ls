/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lf_p3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:45:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/04 14:45:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		print_attribute(char *attr)
{
	int		ret;
	ssize_t i;

	ret = 0;
	i = 0;
	ft_printf("\t");
	while (attr[i] != '\0')
	{
		ret += ft_printf("%c", attr[i]);
		i++;
	}
	ft_printf("\t  ");
	ret++;
	return (ret);
}

int 			print_lf_p3(char *path)
{
	char 		*attr1;
	char 		*attr2;
	ssize_t		i;
	ssize_t 	ret;
	ssize_t 	l;

	i = 0;
	ret = 0;
	l = 0;
	attr1 = ft_strnew(256);
	attr2 = ft_strnew(256);
	if ((i = listxattr(path, attr1, 256, XATTR_NOFOLLOW)) > 0)
	{
		while (i > 0)
		{
			ret += print_attribute(attr1 + l);
			ft_printf("%zd\n",
					  getxattr(path, &attr1[l], attr2, 256, 0, XATTR_NOFOLLOW));
			i -= ret;
			l += ret;
		}
	}
	ft_strdel(&attr1);
	ft_strdel(&attr2);
	return (1);
}