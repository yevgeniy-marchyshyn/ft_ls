/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ibs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:05:06 by ymarchys          #+#    #+#             */
/*   Updated: 2018/01/26 12:14:44 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		itoa_write(char *result, ssize_t n, int base, int *i)
{
	char *s;

	s = "0123456789ABCDEF";
	if (n > 0)
	{
		if (n >= base)
			itoa_write(result, n / base, base, i);
		result[*i] = s[n % base];
	}
	if (n < 0 && n < -base)
	{
		itoa_write(result, (n / base) * -1, base, i);
		result[*i] = s[(n % base) * -1];
	}
	else
	{
		if (n < 0)
			result[*i] = s[(n % base) * -1];
		else
			result[*i] = s[n % base];
	}
	*i += 1;
}

char			*ibs(ssize_t n, int base)
{
	char	*result;
	int		i;

	i = n <= 0 ? 1 : 0;
	if (base < 2 || base > 16 || !(result = (char*)malloc(sizeof(char) * 33)))
		return (NULL);
	if (n == 0 || n < 0)
		result[0] = n < 0 ? '-' : '0';
	if (n != 0)
		itoa_write(result, n, base, &i);
	result[i] = '\0';
	return (result);
}
