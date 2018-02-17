/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:14:55 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/07 16:11:55 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	size_t			i;

	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		to[i] = from[i];
		if (from[i] == (unsigned char)c)
			return (to + i + 1);
		i++;
	}
	return (NULL);
}
