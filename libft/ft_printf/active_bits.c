/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:13:06 by ymarchys          #+#    #+#             */
/*   Updated: 2018/01/17 19:13:09 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			active_bits(unsigned int c)
{
	int result;
	int i;

	i = 1;
	result = 0;
	while (i != 33)
	{
		if (c & 1)
			result = i;
		c >>= 1;
		i++;
	}
	return (result);
}
