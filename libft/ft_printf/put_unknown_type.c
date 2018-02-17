/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_as_it_is.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:26:23 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 10:47:02 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				put_unknown_type(t_printf *p)
{
	int		ret;

	ret = 0;
	if (!p->left_adjustment && p->w > 1)
		ret += p->zero_padding ?
			put_padding('0', p->w - 1) : put_padding(' ', p->w - 1);
	ret += (int)write(1, &p->type, 1);
	if (p->left_adjustment && p->w > 1)
		ret += p->zero_padding ?
			put_padding('0', p->w - 1) : put_padding(' ', p->w - 1);
	return (ret);
}
