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

//static int		hyphen(t_opt *opt, char **argv, int argc, int i, int k)
//{
//	if (argv[i][k + 1] == '\0')
//	{
//		opt->hyphen_file = 1;
//		if (argv[++i])
//			parse_files(argv + i, argc - i, opt);
//		return (1);
//	}
//	return (0);
//}
//
//static int		illegal_option(char **argv, int i, int k)
//{
//	if (!(is_option((argv[i][k])) && argv[i][k] != '\0'))
//	{
//		ft_printf("ft_ls: illegal option -- %c\n", argv[i][k]);
//		ft_printf("usage: ft_ls [-Ralrt] [file ...]\n");
//		return (1);
//	}
//	return (0);
//}

int				parse_options(t_opt *opt, char *argv)
{
	while (*argv && is_option(*argv))
	{
		if (*argv == 'l')
			opt->long_format = 1;
		else if (*argv == 'R')
			opt->recursively = 1;
		else if (*argv == 'a')
			opt->include_dot = 1;
		else if (*argv == 'r')
			opt->rev_lexic = 1;
		else if (*argv == 't')
			opt->sort_mtime = 1;
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

//int				parse_options(t_opt *opt, char **av, int i)
//{
//	av[i]++;
//	while (*av[i] && is_option(*av[i]))
//	{
//		if (*av[i] == 'l')
//			opt->long_format = 1;
//		else if (*av[i] == 'R')
//			opt->recursively = 1;
//		else if (*av[i] == 'a')
//			opt->include_dot = 1;
//		else if (*av[i] == 'r')
//			opt->rev_lexic = 1;
//		else if (*av[i] == 't')
//			opt->sort_mtime = 1;
//		else if (*av[i] == '-')
//			break ;
//		av[i]++;
//	}
//	if (!is_option(*av[i]) && *av[i] != '-')
//		return (0);
//	else if (*av[i] == '-' && !++*av[i])
//		return (1);
//	else
//	{
//		ft_printf("ft_ls: illegal option -- %c\n", *av[i]);
//		ft_printf("usage: ft_ls [-Ralrt] [file ...]\n");
//		exit(1);
//	}
//}


//		else if (argv[i][k] == '-')
//		{
//			if (argv[i][k + 1] == '\0')
//			{
//				opt->hyphen_file = 1;
//				if (argv[++i])
//					parse_files(argv + i, argc - i, opt);
//				return ;
//			}
//			break ;
//		}
