/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:13:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/21 18:13:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_access(mode_t st_mode)
{
	char		*o;
	ssize_t 	value;
	int 		div;
	int 		i;

	o = ibs_uns(st_mode, 8);
	value = ft_atoi(o);
	value %= 1000;
	div = 100;
	i = 0;
	while (i != 3)
	{
		access_flag(value / div);
		value %= div;
		div /= 10;
		i++;
	}
	ft_strdel(&o);
}
