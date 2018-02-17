/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:44:16 by ymarchys          #+#    #+#             */
/*   Updated: 2018/01/21 19:02:35 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_bytes(unsigned int c)
{
	int size;

	size = active_bits(c);
	if (size <= 7)
		return (1);
	else if (size <= 11)
		return (2);
	else if (size <= 16)
		return (3);
	else
		return (4);
}
