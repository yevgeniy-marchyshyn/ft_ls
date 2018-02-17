/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:29:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/16 19:29:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		count_files(t_list *lst)
{
	DIR				*dir;
	int				n;
	struct dirent	*sd;

	n = 0;
	dir = opendir(lst->content);
	while ((sd = readdir(dir)) != NULL)
		n++;
	closedir(dir);
	return (n);
}

static char		**read_files(int n, t_list *lst)
{
	DIR				*dir;
	struct dirent	*sd;
	char 			**files;
	int 			i;

	i = 0;
	dir = opendir(lst->content);
	files = (char**)malloc(sizeof(char*) * (n + 1));
	ft_printf("I am here\n");
	while ((sd = readdir(dir)) != NULL)
	{
		ft_printf("%s\n", sd->d_name);
		files[i++] = ft_strdup(sd->d_name);
	}
	files[i] = NULL;
	closedir(dir);
	return (files);
}

static void		is_dir(t_list *lst, t_opt *opt)
{
	DIR				*dir;
	char 			**files;
	int 			n;

	dir = opendir(lst->content);
	if (dir == NULL)
	{
		ft_printf("%s:\nft_ls: ", lst->content);
		perror(lst->content);
		return ;
	}
	else
	{
		n = count_files(lst->content);
		ft_printf("n = %d\n", n);
		ft_printf("%s: \n", lst->content);
		files = read_files(n, lst);
		if (opt->recursively)
			parse_files(files, n, opt);
	}
	ft_printf("%d\n");
	closedir(dir);
}

static char		check_link(t_list *lst)
{
	struct stat		buf;

	stat(lst->content, &buf);
	return(define_type(&buf));
}

void		ft_ls(t_list *head, t_opt *opt)
{
	t_list *lst;

//	lst = head;
//	while (lst != NULL)
//	{
//		ft_printf("%s has type '%c'");
//		lst = lst->next;
//	}
	lst = head;
	while (lst != NULL)
	{
		if (lst->content_size != 'd')
		{
			if (lst->content_size == 'l')
			{
				if (check_link(lst) != 'd')
					ft_printf("%s\n", lst->content);
			}
			else
				ft_printf("%s\n", lst->content);
		}
		lst = lst->next;
	}
	printf("\n");
	lst = head;
	while (lst != NULL)
	{
		if (lst->content_size == 'd')
			is_dir(lst, opt);
		lst = lst->next;
	}
}
