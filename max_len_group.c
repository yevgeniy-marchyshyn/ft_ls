/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_len_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:18:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/22 15:18:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 		max_len_group(char **files, int n)
{
	struct stat		buf;
	struct group	*gr;
	int				i;
	int 			len;
	int				max_length;

	i = 0;
	max_length = 0;
	while (i < n)
	{
		lstat(files[i++], &buf);
		if (!(gr = getgrgid(buf.st_gid)))
			return (-1);
		len = ft_strlen(gr->gr_name);
		if (len > max_length)
			max_length = len;
	}
	return (max_length);
}