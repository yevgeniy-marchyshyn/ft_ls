/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ibs_uns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:04:27 by ymarchys          #+#    #+#             */
/*   Updated: 2018/01/26 12:13:44 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		itoa_write(char *result, size_t n, int base, int *i)
{
	char *s;
	char bs;

	s = NULL;
	if (base >> 8 == 1)
		s = "0123456789ABCDEF";
	else
		s = "0123456789abcdef";
	bs = (char)base;
	if (n >= (size_t)bs)
		itoa_write(result, n / bs, base, i);
	result[*i] = s[n % bs];
	*i += 1;
}

char			*ibs_uns(size_t n, int base)
{
	char	*result;
	int		i;

	i = n == 0 ? 1 : 0;
	if ((char)base < 2 ||
		(char)base > 16 || !(result = (char*)malloc(sizeof(char) * 33)))
		return (NULL);
	if (n == 0)
		result[0] = '0';
	if (n != 0)
		itoa_write(result, n, base, &i);
	result[i] = '\0';
	return (result);
}
