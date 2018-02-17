/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:30:58 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/04 15:31:03 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prec_diff(wchar_t *ls, unsigned int end)
{
	unsigned int n;
	unsigned int i;
	unsigned int diff;

	i = 0;
	n = 0;
	diff = 0;
	while (ls[i])
	{
		n += count_bytes(ls[i]);
		if (n >= end)
		{
			while (n - end > 1)
				n = n - 1;
			diff = n - end;
			break ;
		}
		else
			i++;
	}
	return (diff);
}
