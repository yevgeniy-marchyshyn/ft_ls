/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:17:41 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/04 13:13:53 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *strnew;

	if (!(strnew = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(strnew, size + 1);
	return (strnew);
}
