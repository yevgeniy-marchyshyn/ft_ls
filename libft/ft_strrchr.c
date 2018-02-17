/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:44:46 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/07 16:06:39 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ptr;
	int				i;
	unsigned char	x;

	ptr = (unsigned char *)s;
	x = (unsigned char)c;
	i = (int)ft_strlen(s);
	if (x == '\0')
		return ((char *)ptr + ft_strlen(s));
	if (!s || !c)
		return (NULL);
	while (i >= 0)
	{
		if (ptr[i] == x)
			return ((char *)ptr + i);
		i--;
	}
	return (NULL);
}
