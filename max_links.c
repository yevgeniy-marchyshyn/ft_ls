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

static void			max_links_annulation(int *i, int *max_length)
{
	*i = 0;
	*max_length = 0;
}

int					max_links(char **files, t_ls *ls, char *path)
{
	t_stat			buf;
	int				i;
	int				max_length;
	int				len;
	char			*tmp;

	max_links_annulation(&i, &max_length);
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
			len = ft_itoa_len(buf.st_nlink);
			len > max_length ? max_length = len : 0;
		}
		i++;
	}
	return (max_length);
}
