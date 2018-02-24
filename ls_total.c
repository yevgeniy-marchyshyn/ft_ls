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
	struct stat		buf;
	int				i;
	int				sum;

	i = 0;
	sum = 0;
	while (files[i])
	{
		if (print_dot(files[i], ls))
		{
			if (path == NULL)
				lstat(files[i++], &buf);
			else
				lstat(ft_strjoin(path, files[i++]), &buf);
			sum += buf.st_blocks;
		}
		else
			i++;
	}
	return (sum);
}
