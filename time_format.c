/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:15:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/21 18:15:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char 	*time_format(time_t n)
{
	char *time;
	char *time_format;

	time = ctime(&n);
	time_format = ft_strsub(time, 4, 12);
	return (time_format);
}
