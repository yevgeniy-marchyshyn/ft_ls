/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modificator_octal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:40:38 by ymarchys          #+#    #+#             */
/*   Updated: 2018/01/22 13:18:15 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*list_continue(t_printf *p, va_list *ap)
{
	if (p->z > 0)
		return (ibs_uns(va_arg(*ap, size_t), 8));
	else if (p->j > 0)
		return (ibs_uns((size_t)va_arg(*ap, uintmax_t), 8));
	else if (p->l == 1)
		return (ibs_uns((size_t)va_arg(*ap, unsigned long int), 8));
	else if (p->l > 1)
		return (ibs_uns((size_t)va_arg(*ap, unsigned long long int), 8));
	else if (p->h == 1)
		return (ibs_uns((unsigned short int)va_arg(*ap, unsigned int), 8));
	else if (p->h > 1)
		return (ibs_uns((unsigned char)va_arg(*ap, unsigned int), 8));
	else
		return (ibs_uns((size_t)va_arg(*ap, unsigned int), 8));
}

char			*modificator_octal(t_printf *p, va_list *ap)
{
	if (p->type == 'O' && p->z > 0)
		return (ibs_uns(va_arg(*ap, size_t), 8));
	else if (p->type == 'O' && p->j > 0)
		return (ibs_uns((size_t)va_arg(*ap, uintmax_t), 8));
	else if (p->type == 'O' && p->l > 1)
		return (ibs_uns((size_t)va_arg(*ap, unsigned long long int), 8));
	else if (p->type == 'O' && p->l == 1)
		return (ibs_uns((size_t)va_arg(*ap, unsigned long int), 8));
	else if (p->type == 'O')
		return (ibs_uns((size_t)va_arg(*ap, unsigned long int), 8));
	else
		return (list_continue(p, ap));
}
