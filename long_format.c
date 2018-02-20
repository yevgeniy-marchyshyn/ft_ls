/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:30:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/20 13:30:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_access(mode_t st_mode)
{

}

static void		print_long_format(char *filename)
{
	struct stat		buf;

	stat(filename, &buf);
	print_access(buf.st_mode);
}

void			long_format(char **files, int n)
{
	int i;

	i = 0;
	ft_printf("total: %zu\n", ls_total(files, n));
	while (i < n)
		print_long_format(files[i++]);
}