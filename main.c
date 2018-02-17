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

//static char		define_type(struct stat *buf)
//{
//	if ((buf->st_mode & S_IFMT) == S_IFIFO)
//		return ('p');
//	else if ((buf->st_mode & S_IFMT) == S_IFCHR)
//		return ('c');
//	else if ((buf->st_mode & S_IFMT) == S_IFDIR)
//		return ('d');
//	else if ((buf->st_mode & S_IFMT) == S_IFBLK)
//		return ('b');
//	else if ((buf->st_mode & S_IFMT) == S_IFLNK)
//		return ('l');
//	else if ((buf->st_mode & S_IFMT) == S_IFSOCK)
//		return ('s');
//	else
//		return ('-');
//}

//static void		sort_ascii_bubble(char **file, int n)
//{
//	char 	*tmp;
//	int		i;
//	int 	k;
//
//	i = 0;
//	k = 0;
//	while (k < n)
//	{
//		i = 0;
//		while (file[i])
//		{
//			if (file[i + 1] && ft_strcmp(file[i], file[i + 1]) > 0)
//			{
//				tmp = file[i];
//				file[i] = file[i + 1];
//				file[i + 1] = tmp;
//			}
//			i++;
//		}
//		k++;
//	}
//}

//static char		check_link(t_list *lst)
//{
//	struct stat		buf;
//
//	stat(lst->content, &buf);
//	return(define_type(&buf));
//}

//static void		is_dir(t_list *lst, t_opt *opt)
//{
//	DIR				*dir;
//	struct dirent	*sd;
////	char 			**files;
//	int 			i;
//
//	opt = NULL;
//	dir = opendir(lst->content);
//	if (dir == NULL)
//	{
//		ft_printf("%s:\nft_ls: ", lst->content);
//		perror(lst->content);
//		return ;
//	}
//	else
//	{
//		i = 0;
//		ft_printf("%s: \n", lst->content);
//		while ((sd = readdir(dir)) != NULL)
//			i++;
//	}
//	ft_printf("%d\n");
//	closedir(dir);
//}

//static void		ft_ls(t_list *head, t_opt *opt)
//{
//	t_list *lst;
//
//	lst = head;
//	while (lst != NULL)
//	{
//		if (lst->content_size != 'd')
//		{
//			if (lst->content_size == 'l')
//			{
//				if (check_link(lst) != 'd')
//					ft_printf("%s\n", lst->content);
//			}
//			else
//				ft_printf("%s\n", lst->content);
//		}
//		lst = lst->next;
//	}
//	printf("\n");
//	lst = head;
//	while (lst != NULL)
//	{
//		if (lst->content_size == 'd')
//			is_dir(lst, opt);
//		lst = lst->next;
//	}
//}

//static void		parse_files(char **argv, int n, t_opt *opt)
//{
//	struct stat		buf;
//	char			**files;
//	t_list			*head;
//	t_list			*elem;
//	int				i;
//	int 			k;
//
//	i = 0;
//	head = NULL;
//	files = (char**)malloc(sizeof(char*) * (n + 1));
//	while (*argv)
//		files[i++] = *argv++;
//	files[i] = NULL;
//	sort_ascii_bubble(files, n);
//	k = 0;
//	while (files[k])
//	{
//		if (lstat(files[k], &buf) == -1)
//		{
//			ft_printf("ft_ls: ");
//			perror(files[k]);
//		}
//		else
//		{
//			elem = ft_lstnew(files[k], define_type(&buf));
//			ft_lst_push_back(&head, elem);
//		}
//		k++;
//	}
//	ft_ls(head, opt);
//}

//static void		parse_options(t_opt *opt, char **argv, int argc, int i)
//{
//	int		k;
//
//	k = 1;
//	while ((is_option(argv[i][k]) || argv[i][k] == '-') && argv[i][k] != '\0')
//	{
//		if (argv[i][k] == 'l')
//			opt->long_format = 1;
//		else if (argv[i][k] == 'R')
//			opt->recursively = 1;
//		else if (argv[i][k] == 'a')
//			opt->include_dot = 1;
//		else if (argv[i][k] == 'r')
//			opt->rev_lexic = 1;
//		else if (argv[i][k] == 't')
//			opt->sort_mtime = 1;
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
//		k++;
//	}
//	if (!(is_option(argv[i][k])) && argv[i][k] != '\0')
//	{
//		ft_printf("ft_ls: illegal option -- %c\n", argv[i][k]);
//		ft_printf("usage: ft_ls [-Ralrt] [file ...]\n");
//		exit(1);
//	}
//}

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
		parse_files(argv + i, argc - i, &opt);
	else
		ft_ls(ft_lstnew(".", 'd'), &opt);
	return (0);
}
