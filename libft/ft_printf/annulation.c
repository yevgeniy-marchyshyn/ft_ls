/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:39:45 by ymarchys          #+#    #+#             */
/*   Updated: 2018/01/21 18:48:39 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	annulation(t_printf *p)
{
	p->alternative_form = 0;
	p->zero_padding = 0;
	p->left_adjustment = 0;
	p->sign = 0;
	p->space = 0;
	p->dot = 0;
	p->h = 0;
	p->l = 0;
	p->j = 0;
	p->z = 0;
	p->type = 0;
	p->w = 0;
	p->p = 0;
	p->w_default = 0;
	p->w_sign = 0;
	p->already_put = 0;
}
