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

static char		**current_directory(void)
{
	char **files;

	files = (char**)malloc(sizeof(char*) * 2);
	files[0] = ft_strdup(".");
	files[1] = NULL;
	return (files);
}

int				main(int argc, char **argv)
{
	t_ls		ls;
	char 		**files;
	int			i;

	i = 1;
	annulation_opt(&ls);
	if (argc > 1)
	{
		while (argv[i] && argv[i][0] == '-' && argv[i][1] != '\0')
			if (parse_options(&ls, ++argv[i++]) == 1)
				break ;
	}
	if (argv[i])
		parse_arguments(argv + i, argc - i, &ls);
	else
	{
		files = current_directory();
		ft_ls(files, &ls);
		free_words(files);
	}
	return (0);
}
