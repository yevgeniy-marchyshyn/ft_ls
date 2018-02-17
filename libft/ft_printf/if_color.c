/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:30:14 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 13:30:15 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char		*list_continue2(char *format, t_printf *p, char esc)
{
	if (ft_strncmp(format, "{whi", 4) == 0 && format[4] == '}')
	{
		write(1, &esc, 1);
		write(1, "[37m", 4);
		p->if_color = 1;
		return (format + 5);
	}
	else
		return (format);
}

static const char		*list_continue(char *format, t_printf *p, char esc)
{
	if (ft_strncmp(format, "{blu", 4) == 0 && format[4] == '}')
	{
		write(1, &esc, 1);
		write(1, "[34m", 4);
		p->if_color = 1;
		return (format + 5);
	}
	if (ft_strncmp(format, "{mag", 4) == 0 && format[4] == '}')
	{
		write(1, &esc, 1);
		write(1, "[35m", 4);
		p->if_color = 1;
		return (format + 5);
	}
	else if (ft_strncmp(format, "{cyn", 4) == 0 && format[4] == '}')
	{
		write(1, &esc, 1);
		write(1, "[36m", 4);
		p->if_color = 1;
		return (format + 5);
	}
	return (list_continue2(format, p, esc));
}

const char				*if_color(char *format, t_printf *p, char esc)
{
	if (ft_strncmp(format, "{red", 4) == 0 && format[4] == '}')
	{
		write(1, &esc, 1);
		write(1, "[31m", 4);
		p->if_color = 1;
		return ((const char*)format + 5);
	}
	else if (ft_strncmp(format, "{grn", 4) == 0 && format[4] == '}')
	{
		write(1, &esc, 1);
		write(1, "[32m", 4);
		p->if_color = 1;
		return ((const char*)format + 5);
	}
	else if (ft_strncmp(format, "{yel", 4) == 0 && format[4] == '}')
	{
		write(1, &esc, 1);
		write(1, "[33m", 4);
		p->if_color = 1;
		return ((const char*)format + 5);
	}
	return ((const char*)list_continue(format, p, esc));
}
