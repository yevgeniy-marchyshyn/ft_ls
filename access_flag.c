/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:00:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/20 23:00:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	access_flag(int value)
{
	if (value == 7)
		ft_printf("rwx");
	else if (value == 6)
		ft_printf("rw-");
	else if (value == 5)
		ft_printf("r-x");
	else if (value == 4)
		ft_printf("r--");
	else if (value == 3)
		ft_printf("-wx");
	else if (value == 2)
		ft_printf("-w-");
	else if (value == 1)
		ft_printf("--x");
	else if (value == 0)
		ft_printf("---");
}
