/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:48:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/16 18:48:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			tous_les_options(char c, t_ls *ls)
{
	if (c == 'l')
		ls->long_format = 1;
	else if (c == 'R')
		ls->recursion = 1;
	else if (c == 'a')
		ls->include_dot = 1;
	else if (c == 'r')
		ls->rev_lexic = 1;
	else if (c == 't')
		ls->sort_mtime = 1;
}

int				parse_options(t_ls *ls, char *argv)
{
	while (*argv && is_option(*argv))
		tous_les_options(*argv++, ls);
	if (!argv[0])
		return (0);
	else if (argv[0] == '-' && argv[1] == '\0')
		return (1);
	else
	{
		write(2, "ls: illegal option -- ", 22);
		write(2, &argv[0], 1);
		write(2, "\n", 1);
		write(2, "usage: ls [-Ralrt] [file ...]\n", 34);
		exit(1);
	}
}
