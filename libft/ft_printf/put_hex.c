/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:26:06 by ymarchys          #+#    #+#             */
/*   Updated: 2018/01/24 20:24:13 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		put_alternative_form(t_printf *p, char c)
{
	int ret;

	ret = 0;
	if (!(p->already_put) && c != '0')
	{
		ret += p->type == 'x' ? (int)write(1, "0x", 2) : (int)write(1, "0X", 2);
		p->already_put = 1;
	}
	return (ret);
}

static int		out_left_adjustment(t_printf *p, char *s, int wid, int prec)
{
	int ret;

	ret = 0;
	ret += p->alternative_form ? put_alternative_form(p, s[0]) : 0;
	ret += put_padding('0', prec);
	ret += (int)write(1, s, ft_strlen(s));
	ret += put_padding(' ',
		wid - (wid && wid > p->w_default ? p->w_default : 0));
	return (ret);
}

static int		out(t_printf *p, char *s, int wid, int prec)
{
	int ret;

	ret = 0;
	if (p->zero_padding && !(p->p) && p->alternative_form)
		ret += put_alternative_form(p, s[0]);
	if (p->zero_padding && !p->dot)
		ret += put_padding('0', wid - (wid >= p->w_default ? p->w_default : 0));
	else
		ret += put_padding(' ', wid - (wid >= p->w_default ? p->w_default : 0));
	ret += p->alternative_form ? put_alternative_form(p, s[0]) : 0;
	ret += put_padding('0', prec);
	ret += !(p->dot && !(p->p) && s[0] == '0') ?
	(int)write(1, s, ft_strlen(s)) : 0;
	return (ret);
}

int				put_hex(t_printf *p, char *s)
{
	int ret;
	int width;
	int precis;
	int	len;

	set_to_zero(&width, &precis, &ret, &len);
	len = (p->dot && !(p->p) && s[0] == '0') ? 0 : (int)ft_strlen(s);
	p->w_default = p->alternative_form && len ? 2 : 0;
	if (p->w > p->p)
		if (p->w > len)
			width = p->p > len ? p->w - p->p : p->w - len;
	precis = (p->p > len) ? p->p - len : 0;
	ret += p->left_adjustment ? out_left_adjustment(p, s, width, precis) :
			out(p, s, width, precis);
	ft_strdel(&s);
	return (ret);
}
