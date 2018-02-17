/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_octal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 21:24:13 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 10:40:32 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			put_alternative_form(t_printf *p)
{
	int ret;

	ret = 0;
	if (!p->already_put)
	{
		ret += (int)write(1, "0", 1);
		p->already_put = 1;
	}
	return (ret);
}

static int			out_left_adjustment(t_printf *p, char *s, int wid, int prec)
{
	int ret;

	ret = 0;
	ret += p->alternative_form ? put_alternative_form(p) : 0;
	ret += put_padding('0', prec);
	ret += (int)write(1, s, ft_strlen(s));
	ret += put_padding(' ', wid);
	return (ret);
}

static int			out(t_printf *p, char *s, int wid, int prec)
{
	int ret;

	ret = 0;
	if (p->zero_padding && !p->p && p->alternative_form)
		ret += put_alternative_form(p);
	if (p->zero_padding && !p->dot)
		ret += put_padding('0', wid - (!p->p && s[0] == '0' &&
		p->alternative_form && p->dot ? 1 : 0));
	else
		ret += put_padding(' ', wid - (!p->p && s[0] == '0' &&
		p->alternative_form && p->dot ? 1 : 0));
	ret += p->alternative_form ? put_alternative_form(p) : 0;
	if (s[0] == '0' && (!p->p && p->dot))
		return (ret);
	ret += put_padding('0', prec);
	ret += (int)write(1, s, ft_strlen(s));
	return (ret);
}

static int			case_with_zero(t_printf *p, int wid)
{
	int ret;

	ret = 0;
	if (p->alternative_form && !p->dot)
		if (p->zero_padding && !p->dot)
			ret += put_padding('0', wid + (p->w ? p->alternative_form : 0));
		else
			ret += put_padding(' ', wid + (p->w ? p->alternative_form : 0));
	else if (p->zero_padding && p->alternative_form && p->dot)
		ret += put_padding(' ', wid - p->alternative_form);
	return (ret + (int)write(1, "0", 1));
}

int					put_octal(t_printf *p, char *s)
{
	int ret;
	int width;
	int precis;
	int	len;

	set_to_zero(&width, &precis, &ret, &len);
	len = p->dot && s[0] == '0' && !p->p ? 0 :
	(int)ft_strlen(s) + p->alternative_form;
	if (p->w > p->p)
		if (p->w && p->w > len)
			width = p->p > len ? p->w - p->p : p->w - len;
	precis = (p->p && p->p > len) ? p->p - len : 0;
	if ((s[0] == '0' && p->alternative_form) && (!p->dot ||
			(p->dot && p->zero_padding)))
		return (case_with_zero(p, width));
	ret += p->left_adjustment ? out_left_adjustment(p, s, width, precis) :
				out(p, s, width, precis);
	ft_strdel(&s);
	return (ret);
}
