/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:03:45 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/03 16:02:24 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*newstr;

	if (!s1 || !s2)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	newstr = ft_strcat(newstr, s1);
	newstr = ft_strcat(newstr, s2);
	return (newstr);
}
