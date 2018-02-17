/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_putchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:08:51 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 10:19:29 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		bytes_4(unsigned char *b, unsigned int c)
{
	unsigned char octet;

	b[3] = (c << 26) >> 26;
	b[2] = ((c >> 6) << 26) >> 26;
	b[1] = ((c >> 12) << 26) >> 26;
	b[0] = ((c >> 18) << 29) >> 29;
	octet = ((unsigned int)MASK_3 >> 24) | b[0];
	write(1, &octet, 1);
	octet = ((unsigned int)MASK_3 << 8) >> 24 | b[1];
	write(1, &octet, 1);
	octet = ((unsigned int)MASK_3 << 16) >> 24 | b[2];
	write(1, &octet, 1);
	octet = ((unsigned int)MASK_3 << 24) >> 24 | b[3];
	write(1, &octet, 1);
	return (4);
}

static int		bytes_3(unsigned char *b, unsigned int c, int size)
{
	unsigned char octet;

	if (size <= 16)
	{
		b[2] = (c << 26) >> 26;
		b[1] = ((c >> 6) << 26) >> 26;
		b[0] = ((c >> 12) << 28) >> 28;
		octet = (unsigned int)MASK_2 >> 16 | b[0];
		write(1, &octet, 1);
		octet = ((unsigned int)MASK_2 << 16) >> 24 | b[1];
		write(1, &octet, 1);
		octet = ((unsigned int)MASK_2 << 24) >> 24 | b[2];
		write(1, &octet, 1);
		return (3);
	}
	else
		return (bytes_4(b, c));
}

int				m_putchar(unsigned int c)
{
	unsigned int	tmp;
	unsigned char	octet;
	unsigned char	b[4];
	int				size;

	size = active_bits(c);
	tmp = c;
	if (size <= 7 || MB_CUR_MAX == 1)
	{
		octet = tmp;
		write(1, &octet, 1);
		return (1);
	}
	else if (size <= 11)
	{
		b[1] = (tmp << 26) >> 26;
		b[0] = ((tmp >> 6) << 27) >> 27;
		octet = (unsigned int)MASK_1 >> 8 | b[0];
		write(1, &octet, 1);
		octet = ((unsigned int)MASK_1 << 24) >> 24 | b[1];
		write(1, &octet, 1);
		return (2);
	}
	else
		return (bytes_3(b, c, size));
}
