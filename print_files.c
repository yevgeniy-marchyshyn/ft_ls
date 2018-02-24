/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:52:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/22 12:52:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_files(char **files, t_ls *ls)
{
	int i;

	i = 0;
	while (files[i])
	{
		if ((!is_dir(files[i])  || ls->recursively) && print_dot(files[i], ls))
		{
			ft_printf("%s\n", files[i]);
			ls->indents = 1;
		}
		i++;
	}
}
