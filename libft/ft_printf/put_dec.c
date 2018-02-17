/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:43:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/01/26 13:43:53 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			put_sign(t_printf *p, char *s)
{
	int ret;

	ret = 0;
	if (!(p->already_put))
	{
		if (p->sign && s[0] != '-')
			ret += (int)write(1, "+", 1);
		else if (s[0] == '-')
			ret += (int)write(1, "-", 1);
		else if (p->space && !(p->sign || s[0] == '-'))
			ret += (int)write(1, " ", 1);
		p->already_put = 1;
	}
	return (ret);
}

static int			out_left_adjustment(t_printf *p, char *s, int wid, int prec)
{
	int ret;

	ret = 0;
	ret += put_sign(p, s);
	ret += put_padding('0', prec);
	ret += s[0] == '-' ? (int)write(1, s + 1, ft_strlen(s + 1)) :
	(int)write(1, s, ft_strlen(s));
	ret += put_padding(' ', wid - (wid ? p->w_sign : 0));
	return (ret);
}

static int			out(t_printf *p, char *s, int wid, int prec)
{
	int ret;

	ret = 0;
	if (p->zero_padding && !p->dot &&
	((p->sign && s[0] != '-') || s[0] == '-' || p->space))
		ret += put_sign(p, s);
	if (p->zero_padding && !p->dot)
		ret += put_padding('0', wid - (wid ? p->w_sign : 0));
	else
		ret += put_padding(' ', wid - (wid ? p->w_sign : 0));
	ret += put_sign(p, s);
	ret += put_padding('0', prec);
	ret += s[0] == '-' ? (int)write(1, s + 1, ft_strlen(s + 1)) :
	(int)write(1, s, ft_strlen(s));
	return (ret);
}

static int			case_with_zero(t_printf *p)
{
	int ret;

	ret = 0;
	ret += put_padding(' ', p->w);
	return (ret);
}

int					put_dec(t_printf *p, char *s)
{
	int ret;
	int width;
	int precis;
	int len;

	set_to_zero(&width, &precis, &ret, &len);
	len = (int)ft_strlen(s) - (s[0] == '-' ? 1 : 0);
	p->w_sign = (p->sign && s[0] != '-') || s[0] == '-' || p->space ? 1 : 0;
	if (p->w > p->p)
		if (p->w && p->w > len)
			width = p->p > len ? p->w - p->p : p->w - len;
	precis = (p->p && p->p > len) ? p->p - len : 0;
	if (p->dot && !p->p && s[0] == '0')
		return (case_with_zero(p));
	ret += p->left_adjustment ? out_left_adjustment(p, s, width, precis) :
			out(p, s, width, precis);
	ft_strdel(&s);
	return (ret);
}
