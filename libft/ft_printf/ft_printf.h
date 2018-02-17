/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:43:15 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/08 16:35:53 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <limits.h>
# include "../libft.h"

# define MASK_1		49280
# define MASK_2		14712960
# define MASK_3		4034953344

typedef	struct		s_printf
{
	char			alternative_form;
	char			zero_padding;
	char			left_adjustment;
	char			sign;
	char			space;
	char			dot;
	char			h;
	char			l;
	char			j;
	char			z;
	char			type;
	char			if_color;
	int				w;
	int				p;
	int				w_default;
	int				w_sign;
	int				already_put;
}					t_printf;

int					ft_printf(const char *format, ...);
int					check_flags_modif(t_printf *p, char c);
int					active_bits(unsigned int c);
int					m_putchar(unsigned int c);
int					m_putstr(char *string, int end, int flag);
void				annulation(t_printf *p);
void				set_to_zero(int *a, int *b, int *c, int *d);
int					is_parse_char(char c);
int					is_flag_mod(char c);
char				*ibs(ssize_t n, int base);
char				*ibs_uns(size_t n, int base);
int					put_percent(t_printf *p);
int					put_dec(t_printf *p, char *string);
char				*modificator_dec(t_printf *op, va_list *ap);
int					put_unsigned(t_printf *p, char *string);
char				*modificator_uns(t_printf *op, va_list *ap);
int					put_lc(t_printf *p, va_list *ap);
int					count_bytes(unsigned int c);
int					put_c(t_printf *p, va_list *ap);
int					put_s(t_printf *p, va_list *ap);
int					put_ls(t_printf *p, va_list *ap);
int					putstr_ls(wchar_t *string, unsigned int end, int flag);
int					strlen_ls(wchar_t *s_wchar);
int					put_hex(t_printf *p, char *s);
char				*modificator_hex(t_printf *p, va_list *ap);
int					put_octal(t_printf *p, char *s);
char				*modificator_octal(t_printf *p, va_list *ap);
int					put_p(t_printf *p, char *s);
int					put_unknown_type(t_printf *p);
int					put_padding(int c, int n);
int					prec_diff(wchar_t *ls, unsigned int end);
int					put_float(t_printf *p, va_list *ap);
int					put_binary(t_printf *p, char *s);
const char			*if_color(char *format, t_printf *p, char esc);
void				color_off(char esc);

#endif
