/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:36:14 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/02 17:02:32 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *tmp;

	tmp = (char *)s;
	if (*tmp == (char)c)
		return (tmp);
	while (*tmp != (char)c && *tmp != '\0')
	{
		tmp++;
		if (*tmp == (char)c)
			return (tmp);
	}
	return (NULL);
}
