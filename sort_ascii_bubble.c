/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_bubble.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:43:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/18 15:43:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_ascii_bubble(char **file, int n)
{
	char		*tmp;
	int			i;
	int			k;

	i = 0;
	k = 0;
	while (k < n - 1)
	{
		i = 0;
		while (file[i])
		{
			if (file[i + 1] && ft_strcmp(file[i], file[i + 1]) > 0)
			{
				tmp = file[i];
				file[i] = file[i + 1];
				file[i + 1] = tmp;
			}
			i++;
		}
		k++;
	}
}
