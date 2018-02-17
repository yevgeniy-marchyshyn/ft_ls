/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:43:16 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 10:42:40 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		choose_putstr(t_printf *p, wchar_t *ls)
{
	int ret;

	ret = 0;
	if (p->w_default)
		ret += putstr_ls(ls, p->w_default, 1);
	else
		ret += putstr_ls(ls, 0, 0);
	return (ret);
}

static int		out_s(t_printf *p, wchar_t *ls)
{
	int ret;
	int width;
	int diff;

	ret = 0;
	diff = 0;
	if (p->dot)
		diff = p->w > p->w_default ? prec_diff(ls, p->w_default) : 0;
	if (ls != NULL)
		width = (p->w > p->w_default) ? p->w + diff - p->w_default : 0;
	else
		ret += (p->zero_padding && !p->left_adjustment) ?
		put_padding('0', p->w) : put_padding(' ', p->w);
	if (!p->left_adjustment && p->w_default)
		ret += (p->zero_padding && !p->left_adjustment) ?
		put_padding('0', width) : put_padding(' ', width);
	ret += choose_putstr(p, ls);
	if (p->left_adjustment && p->w_default)
		ret += (p->zero_padding && !p->left_adjustment) ?
		put_padding('0', width) : put_padding(' ', width);
	return (ret);
}

int				put_ls(t_printf *p, va_list *ap)
{
	int			len;
	wchar_t		*ls;

	len = 0;
	ls = NULL;
	ls = va_arg(*ap, wchar_t*);
	len = ls != NULL ? (int)strlen_ls(ls) : -1;
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
	return (len == -1 ? (int)write(1, "(null)", 6) : out_s(p, ls));
}
