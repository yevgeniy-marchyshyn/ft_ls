/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marchyshyn <ymarchys@student.unit.ua>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:04:53 by marchyshy         #+#    #+#             */
/*   Updated: 2018/02/22 13:04:55 by marchyshy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				max_size(char **files, int n)
{
	struct stat		buf;
	int				i;
	int				max_length;

	i = 0;
	max_length = 0;
	while (i < n)
	{
		lstat(files[i++], &buf);
		if (ft_itoa_len(buf.st_size) > max_length)
			max_length = ft_itoa_len(buf.st_size);
	}
	return (max_length);
}
