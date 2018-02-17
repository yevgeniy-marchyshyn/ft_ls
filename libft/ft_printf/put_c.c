/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:21:22 by ymarchys          #+#    #+#             */
/*   Updated: 2018/01/30 18:21:27 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_c(t_printf *p, va_list *ap)
{
	char	c;
	int		ret;

	ret = 0;
	c = (char)va_arg(*ap, int);
	if (!p->left_adjustment && p->w > p->w_default)
	{
		if (p->zero_padding)
			ret += put_padding('0', p->w - 1);
		else
			ret += put_padding(' ', p->w - 1);
	}
	ret += (int)write(1, &c, 1);
	if (p->left_adjustment && p->w > p->w_default)
		ret += put_padding(' ', p->w - 1);
	return (ret);
}
