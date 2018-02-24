/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:00:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/20 13:00:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	print_dot(char *filename, t_ls *ls)
{
	return ((ls->include_dot && ((char*)filename)[0] == '.') ||
	((char*)filename)[0] != '.');
}