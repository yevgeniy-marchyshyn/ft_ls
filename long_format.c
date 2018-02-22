/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:30:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/20 13:30:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				long_format(char **files, int n, t_ls *ls, char *path)
{
	int			i;
	int 		w[4];

	i = 0;
	w[0] = max_links(files, n);
	w[1] = max_len_user(files, n);
	w[2] = max_len_group(files, n);
	w[3] = max_size(files, n);
	ft_printf("total %lld\n", ls_total(files, n, ls));
	while (i < n)
	{
		if (print_dot(files[i], ls))
			print_long_format(files[i], w, path);
		i++;
	}
}