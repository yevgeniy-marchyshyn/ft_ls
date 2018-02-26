/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir_ext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:35:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/26 20:35:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_dir_ext(char **files, int n, t_ls *ls)
{
	int i;

	i = 0;
	ls_sort(files, n, ls, NULL);
	if (ls->include_dot)
		while (i < n)
			ft_printf("%s\n", files[i++]);
	else
	{
		while (i < n)
		{
			if (files[i][0] != '.')
				ft_printf("%s\n", files[i]);
			i++;
		}
	}
}
