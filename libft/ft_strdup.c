/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:55:13 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/02 15:07:33 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*newstr;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	if (!(newstr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*src)
		newstr[i++] = *src++;
	newstr[i] = '\0';
	return (newstr);
}
