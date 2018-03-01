/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:43:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/01 17:43:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				lf(char **files, t_ls *ls, char *path)
{
	int			i;
	int			w[4];

	i = 0;
	w[0] = max_links(files, path);
	w[1] = max_len_user(files, path);
	w[2] = max_len_group(files, path);
	w[3] = max_size(files, path);
	if (not_empty_directory(path, ls))
		ft_printf("total %lld\n", ls_total(files, ls, path));
	while (files[i])
	{
		if (print_dot(files[i], ls))
			print_long_format(files[i], w, path);
		i++;
	}
}
