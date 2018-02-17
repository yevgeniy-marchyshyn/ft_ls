/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:37:17 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 10:38:06 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			putstr_ls(wchar_t *ls, unsigned int end, int flag)
{
	int				ret;
	unsigned int	n;
	unsigned int	i;

	i = 0;
	ret = 0;
	n = 0;
	if (flag == 1)
		while (i < end && ls[i] != '\0')
		{
			n += count_bytes(ls[i]);
			if (n > end)
				break ;
			else
				ret += m_putchar(ls[i++]);
		}
	else
		while (ls[i] != '\0')
			ret += m_putchar(ls[i++]);
	return (ret);
}
