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
//(ls->include_dot && ((char*)lst->content)[0] == '.') ||
//((char*)lst->content)[0] != '.')

int 	print_dot(void *content, t_ls *ls)
{
	return ((ls->include_dot && ((char*)content)[0] == '.') ||
	((char*)content)[0] != '.');
}