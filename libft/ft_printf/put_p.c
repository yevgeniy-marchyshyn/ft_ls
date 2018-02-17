/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:53:15 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 10:44:41 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		case_with_zero(t_printf *p, char *s)
{
	int ret;

	ret = 0;
	if (p->dot && !p->p)
		return (ret);
	else
		return (ret + (!p->dot && p->zero_padding ?
		0 : (int)write(1, s, ft_strlen(s))));
}

static int		put_0x(t_printf *p)
{
	int ret;

	ret = 0;
	if (!p->already_put)
	{
		ret += (int)write(1, "0x", 2);
		p->already_put = 1;
	}
	return (ret);
}

static int		out_left_adjustment(t_printf *p, char *s, int wid, int prec)
{
	int ret;

	ret = 0;
	ret += (int)write(1, "0x", 2);
	ret += put_padding('0', prec);
	ret += (int)write(1, s, ft_strlen(s));
	ret += put_padding(' ', wid - (s[0] == '0' && !p->dot ? 1 : 0));
	return (ret);
}

static int		out(t_printf *p, char *s, int wid, int prec)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	ret += p->zero_padding && !p->dot ? put_0x(p) : 0;
	if (p->zero_padding && !p->dot)
		ret += put_padding('0', wid - (s[0] == '0' &&
		!p->dot && !p->zero_padding ? 1 : 0));
	else
		ret += put_padding(' ', wid - (s[0] == '0' &&
		!p->dot && !p->zero_padding ? 1 : 0));
	ret += put_0x(p);
	ret += put_padding('0', prec);
	return (ret + (s[0] == '0' ?
	case_with_zero(p, s) : (int)write(1, s, ft_strlen(s))));
}

int				put_p(t_printf *p, char *s)
{
	int ret;
	int width;
	int precis;
	int	len;

	set_to_zero(&width, &precis, &ret, &len);
	len = s[0] == '0' && !p->p ? 0 : (int)ft_strlen(s);
	if (p->w > p->p)
		if (p->w && p->w > len)
			width = p->p > len ? p->w - p->p - 2 : p->w - len - 2;
	precis = (p->p && p->p > len) ? p->p - len : 0;
	ret += p->left_adjustment ? out_left_adjustment(p, s, width, precis) :
			out(p, s, width, precis);
	ft_strdel(&s);
	return (ret);
}
