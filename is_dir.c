/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 13:44:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/24 13:44:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_dir(char *filename)
{
	struct stat		buf;
	char 			type;

	lstat(filename, &buf);
	type = define_type(&buf);
	if (type == 'd')
		return (1);
	else
		return (0);
}
