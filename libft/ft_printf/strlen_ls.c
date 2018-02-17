/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:36:19 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 10:47:13 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					strlen_ls(wchar_t *ls)
{
	unsigned int	i;
	int				len;

	i = 0;
	len = 0;
	if (ls)
		while (ls[i])
			len += count_bytes(ls[i++]);
	return (len);
}
