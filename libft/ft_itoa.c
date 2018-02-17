/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:43:13 by exam              #+#    #+#             */
/*   Updated: 2018/01/09 11:20:10 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_itoa_len(long long int n)
{
	int size;

	size = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nbr)
{
	char			*result;
	long long int	n;
	int				i;

	n = nbr;
	if (!(result = (char*)malloc(sizeof(char) * (ft_itoa_len(n) + 1))))
		return (NULL);
	result[ft_itoa_len(n)] = '\0';
	if (n == 0)
		result[0] = '0';
	else
	{
		if (n < 0)
			result[0] = '-';
		i = ft_itoa_len(n) - 1;
		while (n != 0)
		{
			result[i--] = (n < 0) ? -n % 10 + '0' : n % 10 + '0';
			n /= 10;
		}
	}
	return (result);
}
