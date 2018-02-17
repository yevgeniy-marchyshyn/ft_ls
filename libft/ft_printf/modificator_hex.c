/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modificator_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:39:12 by ymarchys          #+#    #+#             */
/*   Updated: 2018/01/22 12:41:20 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*modificator_hex(t_printf *p, va_list *ap)
{
	int bs;

	bs = p->type == 'X' ? 272 : 16;
	if (p->z > 0)
		return (ibs_uns(va_arg(*ap, size_t), bs));
	if (p->j > 0)
		return (ibs_uns((size_t)va_arg(*ap, uintmax_t), bs));
	if (p->l == 1)
		return (ibs_uns((size_t)va_arg(*ap, unsigned long int), bs));
	if (p->l > 1)
		return (ibs_uns((size_t)va_arg(*ap, unsigned long long int), bs));
	if (p->h == 1)
		return (ibs_uns((unsigned short int)va_arg(*ap, int), bs));
	if (p->h > 1)
		return (ibs_uns((unsigned char)va_arg(*ap, int), bs));
	else
		return (ibs_uns(va_arg(*ap, unsigned int), bs));
}
