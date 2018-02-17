/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 18:59:51 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 10:36:32 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			and_fraction(t_printf *p, double n, size_t integer)
{
	char	*out;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (i < p->p)
	{
		n = (n - integer) * 10;
		integer = (size_t)n;
		out = ibs(integer, 10);
		ret += (int)write(1, out, ft_strlen(out));
		ft_strdel(&out);
		i++;
	}
	return (ret);
}

static int			put_sign(t_printf *p, double n, int minus)
{
	int ret;

	ret = 0;
	if (!minus && p->space)
		ret += (int)write(1, " ", 1);
	if (p->sign && !minus && n != 0)
		ret += (int)write(1, "+", 1);
	if (minus)
		ret += (int)write(1, "-", 1);
	return (ret);
}

static int			no_precision(t_printf *p, double n, size_t integ, int min)
{
	int		ret;
	char	*out;

	ret = 0;
	n -= integ;
	if ((size_t)(n * 10) > 5)
		out = ibs(integ + 1, 10);
	else
		out = ibs(integ, 10);
	p->w_default = (int)ft_strlen(out);
	p->w -= p->w_default + p->w_sign + (p->p ? 1 + p->p : 0);
	ret += p->zero_padding && !p->left_adjustment ?
	put_padding('0', p->w) : put_padding(' ', p->w);
	ret += put_sign(p, n, min);
	ret += (int)write(1, out, ft_strlen(out));
	return (ret);
}

static int			integer_and_fraction(t_printf *p, double n, int minus)
{
	int			ret;
	size_t		integer;
	char		*out;

	ret = 0;
	integer = (size_t)n;
	p->w_sign = ((p->sign && !minus && n != 0) || p->space || minus) ? 1 : 0;
	if (p->dot && !p->p)
		return (no_precision(p, n, integer, minus));
	out = ibs_uns(integer, 10);
	p->w_default = (int)ft_strlen(out);
	p->w -= p->w_default + p->w_sign + (p->p ? 1 + p->p : 0);
	ret += p->zero_padding && !p->left_adjustment ?
		put_padding('0', p->w) : put_padding(' ', p->w);
	ret += put_sign(p, n, minus);
	ret += (int)write(1, out, (size_t)p->w_default);
	if (p->p != 0)
		ret += (int)write(1, ".", 1);
	ret += and_fraction(p, n, integer);
	ft_strdel(&out);
	return (ret);
}

int					put_float(t_printf *p, va_list *ap)
{
	int			ret;
	int			minus;
	double		n;

	ret = 0;
	minus = 0;
	n = va_arg(*ap, double);
	if (!p->dot)
		p->p = 6;
	if (n < 0)
	{
		n *= -1;
		minus = 1;
	}
	n += 1.0 / ft_power(10, (unsigned int)(p->p + 1));
	ret += integer_and_fraction(p, n, minus);
	return (ret);
}
