/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:12:38 by ymarchys          #+#    #+#             */
/*   Updated: 2018/01/26 14:37:24 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			out_left_adjustment(char *s, int wid, int prec)
{
	int ret;

	ret = 0;
	ret += put_padding('0', prec);
	ret += (int)write(1, s, ft_strlen(s));
	ret += put_padding(' ', wid);
	return (ret);
}

static int			out(t_printf *p, char *s, int wid, int prec)
{
	int ret;

	ret = 0;
	if (p->zero_padding && !p->dot)
		ret += put_padding('0', wid);
	else
		ret += put_padding(' ', wid);
	ret += put_padding('0', prec);
	if (s[0] == '-')
		ret += (int)write(1, s + 1, ft_strlen(s + 1));
	else
		ret += s[0] == '0' && p->dot ? 0 : (int)write(1, s, ft_strlen(s));
	return (ret);
}

int					put_unsigned(t_printf *p, char *s)
{
	int ret;
	int width;
	int precis;
	int len;

	ret = 0;
	set_to_zero(&width, &precis, &ret, &len);
	len = (int)ft_strlen(s);
	if (p->w > p->p)
		if (p->w && p->w > len)
			width = p->p > len ? p->w - p->p : p->w - len;
	precis = (p->p && p->p > len) ? p->p - len : 0;
	ret += p->left_adjustment ? out_left_adjustment(s, width, precis) :
			out(p, s, width, precis);
	ft_strdel(&s);
	return (ret);
}
