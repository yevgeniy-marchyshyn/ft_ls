/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 08:50:33 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 08:50:42 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_power(size_t value, unsigned int power)
{
	unsigned int	i;
	size_t			n;

	if (power == 0)
		return (1);
	i = 1;
	n = value;
	while (i < power)
	{
		n = n * value;
		i++;
	}
	return (n);
}
