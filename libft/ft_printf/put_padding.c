/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:08:14 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 10:45:26 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_padding(int c, int n)
{
	int			ret;
	char		*content;
	int			i;

	ret = 0;
	i = 0;
	content = (char*)malloc(sizeof(char) * (n + 1));
	if (n < 0)
		return (0);
	while (i < n)
		content[i++] = c;
	content[i] = '\0';
	ret += (int)write(1, content, (size_t)n);
	ft_strdel(&content);
	return (ret);
}
