/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:16:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/21 18:16:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*linkpath(char *filename)
{
	char	*buff;

	buff = ft_strnew(128);
	readlink(filename, buff, 127);
	return (buff);
}