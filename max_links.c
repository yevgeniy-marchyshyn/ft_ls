/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marchyshyn <ymarchys@student.unit.ua>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:04:22 by marchyshy         #+#    #+#             */
/*   Updated: 2018/02/22 13:04:25 by marchyshy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 			max_links(char **files, int n)
{
	struct stat		buf;
	int				i;
	int				max_length;

	i = 0;
	max_length = 0;
	while (i < n)
	{
		lstat(files[i++], &buf);
		if (ft_itoa_len(buf.st_nlink) > max_length)
			max_length = ft_itoa_len(buf.st_nlink);
	}
	return (max_length);
}
