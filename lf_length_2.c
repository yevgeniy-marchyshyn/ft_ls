/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_length_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:43:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/21 18:43:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				lf_length_2(char **files, int n)
{
	struct stat		buf;
	int				i;
	int				max_length;

	i = 0;
	max_length = 0;
	while (i < n)
	{
		lstat(files[i++], &buf);
		if (ft_itoa_len(buf.st_size) > max_length)
			max_length = ft_itoa_len(buf.st_size);
	}
	return (max_length);
}
