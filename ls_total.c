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

int		ls_total(char **files, int n, t_ls *ls)
{
	struct stat		buf;
	int				i;
	int				sum;

	i = 0;
	sum = 0;
	while (i < n)
	{
		if (print_dot(files[i], ls))
		{
			stat(files[i++], &buf);
			sum += buf.st_blocks;
		}
		else
			i++;
	}
	return (sum);
}
