/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:07:04 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 16:07:09 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_binary(t_printf *p, char *s)
{
	int ret;
	int len;

	ret = 0;
	len = (int)ft_strlen(s);
	if (!p->left_adjustment && p->p > len)
	{
		if (p->zero_padding)
			ret += put_padding('0', p->p - len);
		else
			ret += put_padding(' ', p->p - len);
	}
	ret += (int)write(1, s, ft_strlen(s));
	if (p->left_adjustment && p->p > len)
		ret += put_padding(' ', p->p - len);
	ft_strdel(&s);
	return (ret);
}
