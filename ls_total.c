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

quad_t		ls_total(char **files, int n)
{
	struct stat		buf;
	int				i;
	quad_t			sum;

	i = 0;
	sum = 0;
	while (i < n)
	{
		stat(files[i++], &buf);
		sum += buf.st_blocks;
	}
	return (sum);
}
