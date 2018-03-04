/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_total.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:00:28 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/20 14:00:29 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_total(char **files, t_ls *ls, char *path)
{
	t_stat			buf;
	int				i;
	int				sum;
	char 			*tmp;

	i = 0;
	sum = 0;
	while (files[i])
	{
		if (print_dot(files[i], ls) || ls->not_sort)
		{
			if (path == NULL)
				lstat(files[i++], &buf);
			else
			{
				tmp = ft_strjoin(path, files[i++]);
				lstat(tmp, &buf);
				ft_strdel(&tmp);
			}
			sum += buf.st_blocks;
		}
		else
			i++;
	}
	return (sum);
}
