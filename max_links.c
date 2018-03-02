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

int					max_links(char **files, char *path)
{
	t_stat			buf;
	int				i;
	int				max_length;
	char 			*tmp;

	i = 0;
	max_length = 0;
	while (files[i])
	{
		if (path == NULL)
			lstat(files[i++], &buf);
		else
		{
			tmp = ft_strjoin(path, files[i++]);
			lstat(tmp, &buf);
			ft_strdel(&tmp);
		}
		if (ft_itoa_len(buf.st_nlink) > max_length)
			max_length = ft_itoa_len(buf.st_nlink);
	}
	return (max_length);
}
