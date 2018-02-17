/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:32:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/16 12:32:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 			main(int argc, char **argv)
{
	t_opt	opt;
	int 	i;

	i = 1;
	annulation_opt(&opt);
	if (argc > 1)
	{
		while (argv[i] && argv[i][0] == '-')
			if (parse_options(&opt, ++argv[i++]) == 1)
				break;
	}
//	ft_printf("l: %d\n", opt.long_format);
//	ft_printf("R: %d\n", opt.recursively);
//	ft_printf("r: %d\n", opt.rev_lexic);
//	ft_printf("a: %d\n", opt.include_dot);
//	ft_printf("t: %d\n", opt.sort_mtime);
	if (argv[i])
		parse_files(argv + i, argc - i, &opt);
	else
		ft_ls(ft_lstnew(".", 'd'), &opt);
	return (0);
}
