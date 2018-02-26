/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_dots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:40:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/20 12:40:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		skip_dots(char *filename)
{
	return (ft_strcmp(filename, ".") != 0 && ft_strcmp(filename, "..") != 0);
}
