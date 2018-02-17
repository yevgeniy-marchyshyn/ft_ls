/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:32:41 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/07 13:24:36 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		result;
	size_t	i;

	result = 0;
	i = 0;
	if (!n)
		return (0);
	while (s1[i] == s2[i] && i < n - 1)
	{
		i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			return (result);
	}
	result = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (result);
}
