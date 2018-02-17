/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:13:15 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 10:45:45 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_percent(t_printf *p)
{
	int ret;

	ret = 0;
	if (!p->left_adjustment && p->w > 1)
	{
		if (p->zero_padding)
			ret += put_padding('0', p->w - 1);
		else
			ret += put_padding(' ', p->w - 1);
	}
	ret += (int)write(1, "%", 1);
	if (p->left_adjustment && p->w > 1)
		ret += put_padding(' ', p->w - 1);
	return (ret);
}
