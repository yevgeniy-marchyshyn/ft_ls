/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:43:59 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/07 13:45:58 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				result;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	result = 0;
	if (!n)
		return (0);
	while (*str1 == *str2 && --n)
	{
		str1++;
		str2++;
	}
	result = (unsigned char)*str1 - (unsigned char)*str2;
	return (result);
}
