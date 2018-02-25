/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_into_a_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 14:24:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/25 14:24:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char 	*join_into_a_path(char *file1, char *file2)
{
	char 	*result;

	result = ft_strjoin(file1, file2);
	if (file1)
		ft_strdel(&file1);
	if (file2)
		ft_strdel(&file2);
	return (result);
}
