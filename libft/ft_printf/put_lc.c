/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:08:29 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/05 14:08:31 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			out(t_printf *p, unsigned int c)
{
	int ret;

	ret = 0;
	if (!p->left_adjustment && p->w > p->w_default)
	{
		if (p->zero_padding)
			ret += put_padding('0', p->w - p->w_default);
		else
			ret += put_padding(' ', p->w - p->w_default);
	}
	ret += m_putchar(c);
	if (p->left_adjustment && p->w > p->w_default)
		ret += put_padding(' ', p->w - p->w_default);
	return (ret);
}

int					put_lc(t_printf *p, va_list *ap)
{
	unsigned int	c;

	c = va_arg(*ap, unsigned int);
	p->w_default = count_bytes(c);
	return (out(p, c));
}
