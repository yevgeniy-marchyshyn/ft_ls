/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modificator_uns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:18:39 by ymarchys          #+#    #+#             */
/*   Updated: 2018/01/26 14:37:58 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*list_continue(t_printf *p, va_list *ap)
{
	if (p->type == 'U' && p->z > 0)
		return (ibs_uns(va_arg(*ap, size_t), 10));
	else if (p->type == 'U' && p->j > 0)
		return (ibs_uns(va_arg(*ap, uintmax_t), 10));
	else if (p->type == 'U' && p->l == 1)
		return (ibs_uns((size_t)va_arg(*ap, unsigned long int), 10));
	else if (p->type == 'U' && p->l > 1)
		return (ibs_uns((size_t)va_arg(*ap, unsigned long long int), 10));
	else
		return (ibs_uns((size_t)va_arg(*ap, unsigned long int), 10));
}

char			*modificator_uns(t_printf *p, va_list *ap)
{
	if (p->type == 'u' && p->z > 0)
		return (ibs_uns(va_arg(*ap, size_t), 10));
	else if (p->type == 'u' && p->j > 0)
		return (ibs_uns(va_arg(*ap, uintmax_t), 10));
	else if (p->type == 'u' && p->l == 1)
		return (ibs_uns((size_t)va_arg(*ap, unsigned long int), 10));
	else if (p->type == 'u' && p->l > 1)
		return (ibs_uns((size_t)va_arg(*ap, unsigned long long int), 10));
	else if (p->type == 'u' && p->h == 1)
		return (ibs_uns((unsigned short int)va_arg(*ap, unsigned int), 10));
	else if (p->type == 'u' && p->h > 1)
		return (ibs_uns((unsigned char)va_arg(*ap, unsigned int), 10));
	else if (p->type == 'u')
		return (ibs_uns((size_t)va_arg(*ap, unsigned int), 10));
	else
		return (list_continue(p, ap));
}
