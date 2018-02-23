/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_len_user.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:11:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/22 15:11:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 		max_len_user(char **files, int n)
{
	struct stat		buf;
	struct passwd	*pw;
	int				i;
	int 			len;
	int				max_length;

	i = 0;
	max_length = 0;
	while (i < n)
	{
		lstat(files[i++], &buf);
		if (!(pw = getpwuid(buf.st_uid)))
			return (-1);
		len = ft_strlen(pw->pw_name);
		if (len > max_length)
			max_length = len;
	}
	return (max_length);
}