/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modificator_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:38:29 by ymarchys          #+#    #+#             */
/*   Updated: 2018/01/25 18:57:15 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*list_continue(t_printf *p, va_list *ap)
{
	if (p->z > 0)
		return (ibs((ssize_t)va_arg(*ap, ssize_t), 10));
	else if (p->j > 0)
		return (ibs(va_arg(*ap, intmax_t), 10));
	else if (p->l == 1)
		return (ibs((ssize_t)va_arg(*ap, long int), 10));
	else if (p->l > 1)
		return (ibs((ssize_t)va_arg(*ap, long long int), 10));
	else if (p->h == 1)
		return (ibs((short int)va_arg(*ap, int), 10));
	else if (p->h > 1)
		return (ibs((signed char)va_arg(*ap, int), 10));
	else
		return (ibs((ssize_t)va_arg(*ap, int), 10));
}

char			*modificator_dec(t_printf *p, va_list *ap)
{
	if (p->type == 'D' && p->z > 0)
		return (ibs((ssize_t)va_arg(*ap, ssize_t), 10));
	else if (p->type == 'D' && p->j > 0)
		return (ibs(va_arg(*ap, intmax_t), 10));
	else if (p->type == 'D' && p->l > 1)
		return (ibs((ssize_t)va_arg(*ap, long long int), 10));
	else if (p->type == 'D' && p->l == 1)
		return (ibs((ssize_t)va_arg(*ap, long int), 10));
	else if (p->type == 'D')
		return (ibs((ssize_t)va_arg(*ap, long int), 10));
	else
		return (list_continue(p, ap));
}
