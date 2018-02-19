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

int				parse_options(t_ls *ls, char *argv)
{
	while (*argv && is_option(*argv))
	{
		if (*argv == 'l')
			ls->long_format = 1;
		else if (*argv == 'R')
			ls->recursively = 1;
		else if (*argv == 'a')
			ls->include_dot = 1;
		else if (*argv == 'r')
			ls->rev_lexic = 1;
		else if (*argv == 't')
			ls->sort_mtime = 1;
		argv++;
	}
	if (!argv[0])
		return (0);
	else if (argv[0] == '-' && argv[1] == '\0')
		return (1);
	else
	{
		ft_printf("ft_ls: illegal option -- %c\n", argv[0]);
		ft_printf("usage: ft_ls [-Ralrt] [file ...]\n");
		exit(1);
	}
}

