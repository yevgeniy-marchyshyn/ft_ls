/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:33:06 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/07 16:46:58 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *s1, const char *s2, size_t dstsize)
{
	size_t l;

	l = ft_strlen(s1);
	if (dstsize > l)
		ft_strncat(s1, s2, (dstsize - l - 1));
	if (dstsize < l)
		return (dstsize + ft_strlen(s2));
	else
		return (l + ft_strlen(s2));
}
