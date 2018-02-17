/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_putstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:43:40 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/04 19:01:30 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			m_putstr(char *string, int end, int flag)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	if (flag == 1)
		while (i < end)
			ret += m_putchar(string[i++]);
	else
		while (string[i])
			ret += m_putchar(string[i++]);
	return (ret);
}
