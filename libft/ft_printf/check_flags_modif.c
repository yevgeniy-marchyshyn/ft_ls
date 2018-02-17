/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_modif.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:47:58 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 15:48:05 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_flags_modif(t_printf *p, char c)
{
	if (c == '#')
		p->alternative_form = 1;
	else if (c == '0')
		p->zero_padding = 1;
	else if (c == '-')
		p->left_adjustment = 1;
	else if (c == '+')
		p->sign = 1;
	else if (c == ' ')
		p->space = 1;
	else if (c == 'l')
		p->l += 1;
	else if (c == 'h')
		p->h += 1;
	else if (c == 'j')
		p->j = 1;
	else if (c == 'z')
		p->z = 1;
	return (1);
}
