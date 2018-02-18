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
	if (argv[i])
		parse_arguments(argv + i, argc - i, &opt);
	else
		ft_ls(ft_lstnew(".", 'd'), &opt);
	return (0);
}
