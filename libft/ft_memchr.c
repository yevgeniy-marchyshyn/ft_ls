/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:22:45 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/07 16:46:44 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	chr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == chr)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
