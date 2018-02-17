/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:02:40 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/07 13:22:32 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int result;

	result = 0;
	while (*s1 == *s2)
	{
		s1++;
		s2++;
		if (*s1 == '\0' && *s2 == '\0')
			return (result);
	}
	result = (unsigned char)*s1 - (unsigned char)*s2;
	return (result);
}
