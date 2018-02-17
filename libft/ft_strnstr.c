/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:40:33 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/07 16:06:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t l;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		l = 0;
		if (haystack[i] == needle[j])
		{
			l = i;
			while (needle[j] != '\0' && haystack[l] == needle[j] && l < len)
			{
				if (needle[j + 1] == '\0' && needle[j] == haystack[l])
					return ((char *)haystack + i);
				l++;
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
