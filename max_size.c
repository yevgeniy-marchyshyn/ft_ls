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

int				max_size(char **files, t_ls *ls, char *path)
{
	t_stat			buf;
	int				i;
	int				max_length;
	int 			len;
	char 			*tmp;

	i = 0;
	max_length = 0;
	while (files[i])
	{
		if (print_dot(files[i], ls))
		{
			if (path == NULL)
				lstat(files[i], &buf);
			else
			{
				tmp = ft_strjoin(path, files[i]);
				lstat(tmp, &buf);
				ft_strdel(&tmp);
			}
			len = ft_itoa_len(buf.st_size);
			len > max_length ? max_length = len : 0;
		}
		i++;
	}
	return (max_length);
}
