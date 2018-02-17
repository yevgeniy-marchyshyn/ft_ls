/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:47:31 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 09:47:34 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"

static int				type_printf(va_list *ap, t_printf *p)
{
	if (p->type == '%')
		return (put_percent(p));
	if (p->type == 'd' || p->type == 'D' || p->type == 'i')
		return (put_dec(p, modificator_dec(p, ap)));
	else if (p->type == 'u' || p->type == 'U')
		return (put_unsigned(p, modificator_uns(p, ap)));
	else if (p->type == 'C' || (p->type == 'c' && p->l))
		return (put_lc(p, ap));
	else if (p->type == 'c' && !p->l)
		return (put_c(p, ap));
	else if (p->type == 's' && !p->l)
		return (put_s(p, ap));
	else if (p->type == 'S' || (p->type == 's' && p->l))
		return (put_ls(p, ap));
	else if (p->type == 'x' || p->type == 'X')
		return (put_hex(p, modificator_hex(p, ap)));
	else if (p->type == 'o' || p->type == 'O')
		return (put_octal(p, modificator_octal(p, ap)));
	else if (p->type == 'p')
		return (put_p(p, ibs_uns((size_t)va_arg(*ap, void*), 16)));
	else if (p->type == 'f' || p->type == 'F')
		return (put_float(p, ap));
	else if (p->type == 'b')
		return (put_binary(p, ibs_uns(va_arg(*ap, size_t), 2)));
	return (put_unknown_type(p));
}

static char				*parse_precision(char *format, va_list *ap, t_printf *p)
{
	if (*format == '*')
	{
		p->p = va_arg(*ap, int);
		if (p->p < 0)
		{
			p->p = 0;
			p->dot = 0;
		}
		format++;
	}
	else
	{
		p->p = ft_atoi(format);
		while (ft_isdigit(*format) && *format)
			format++;
	}
	return (format);
}

static const char		*parse_format(char *format, va_list *ap, t_printf *p)
{
	while (!p->type && *format)
	{
		while (is_flag_mod(*format) && *format)
			format += check_flags_modif(p, *format);
		if (ft_isdigit(*format) || *format == '*')
		{
			p->w = *format == '*' ? va_arg(*ap, int) : ft_atoi(format);
			if (*format == '*')
			{
				if (p->w < 0)
				{
					p->left_adjustment = 1;
					p->w = ABS(p->w);
				}
				format++;
			}
			else
				while (ft_isdigit(*format) && *format)
					format++;
		}
		if (*format == '.' && (p->dot = 1) && *format)
			format = parse_precision(++format, ap, p);
		!is_parse_char(*format) && *format ? p->type = *format : 0;
	}
	return ((const char*)(*format == '\0' ? format : format + 1));
}

static int				do_printf(const char *format, t_printf *p, va_list *ap)
{
	int ret;

	ret = 0;
	p->if_color = 0;
	while (*format)
	{
		if (*format == '%')
		{
			annulation(p);
			format = parse_format((char*)++format, ap, p);
			ret += p->type ? type_printf(ap, p) : 0;
		}
		else if (*format == '{')
		{
			format = if_color((char*)format, p, 27);
			ret += *format == '{' ? (int)write(1, (void*)format++, 1) : 0;
		}
		else
			ret += (int)write(1, (void*)format++, 1);
	}
	p->if_color ? color_off(27) : 0;
	return (ret);
}

int						ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;
	t_printf	p;

	ret = 0;
	va_start(ap, format);
	ret += do_printf(format, &p, &ap);
	va_end(ap);
	return (ret);
}
