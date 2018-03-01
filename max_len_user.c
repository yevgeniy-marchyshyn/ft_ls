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

static int 			length_compare(struct stat *buf, int max_length)
{
	int 			len;
	struct passwd	*pw;

	if (!(pw = getpwuid(buf->st_uid)))
		return (-1);
	len = ft_strlen(pw->pw_name);
	return (len > max_length ? len : max_length);
}

int					max_len_user(char **files, char *path)
{
	struct stat		buf;
	int				i;
	int				max_length;
	char 			*tmp;

	i = 0;
	max_length = 0;
	while (files[i])
	{
		if (path == NULL)
			lstat(files[i++], &buf);
		else
		{
			tmp = ft_strjoin(path, files[i++]);
			lstat(tmp, &buf);
			ft_strdel(&tmp);
		}
		if ((max_length = length_compare(&buf, max_length)) < 0)
			return (-1);
	}
	return (max_length);
}
