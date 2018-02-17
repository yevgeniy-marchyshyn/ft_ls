/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 13:11:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 11:11:33 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		choose_putstr(t_printf *p, char *s)
{
	int ret;

	ret = 0;
	if (p->w_default)
		ret += m_putstr(s, p->w_default, 1);
	else
		ret += ft_putstr(s);
	return (ret);
}

static int		out_s(t_printf *p, char *s)
{
	int ret;
	int width;

	ret = 0;
	if (s[0] != '\0')
		width = (p->w > p->w_default) ? p->w - p->w_default : 0;
	else
		ret += (p->zero_padding && !p->left_adjustment) ?
		put_padding('0', p->w) : put_padding(' ', p->w);
	if (!p->left_adjustment && p->w_default)
		ret += (p->zero_padding && !p->left_adjustment) ?
		put_padding('0', width) : put_padding(' ', width);
	ret += choose_putstr(p, s);
	if (p->left_adjustment && p->w_default)
		ret += (p->zero_padding && !p->left_adjustment) ?
		put_padding('0', width) : put_padding(' ', width);
	return (ret);
}

int				put_s(t_printf *p, va_list *ap)
{
	int			len;
	char		*s;

	len = 0;
	s = NULL;
	s = va_arg(*ap, char*);
	len = s != NULL ? (int)ft_strlen(s) : -1;
	if (p->dot && !p->p)
	{
		if (p->zero_padding && !p->left_adjustment)
			return (put_padding('0', p->w));
		else
			return (put_padding(' ', p->w));
	}
	if (p->dot)
		p->w_default = p->p < len ? p->p : len;
	else
		p->w_default = len;
	if (p->dot && len == -1 && p->p < 7)
		return ((int)write(1, "(null)", p->p));
	return (len == -1 ? (int)write(1, "(null)", 6) : out_s(p, s));
}
