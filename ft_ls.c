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

static int		ls_count_files(char *dirname)
{
	DIR				*dir;
	struct dirent	*sd;
	int 			n;

	n = 0;
	dir = opendir(dirname);
	if (dir == NULL)
	{
		ft_printf("\n%s:\nft_ls: ", dirname);
		perror(dirname);
		return (n);
	}
	ft_printf("\n%s\n", dirname);
	if (dir)
	{
		while ((sd = readdir(dir)) != NULL)
			n++;
	}
	closedir(dir);
	return (n);
}

static char		**read_files(char **files, char *dirname)
{
	DIR					*dir;
	struct dirent		*sd;
	int 				i;

	i = 0;
	dir = opendir(dirname);
	if (dir == NULL)
		return (NULL);
	else
		while ((sd = readdir(dir)) != NULL)
		{
			files[i++] = ft_strdup(sd->d_name);
		}
	files[i] = NULL;
	closedir(dir);
	return (files);
}

static void		ls_readdir(char *dirname, t_opt *opt)
{
	char			**files;
	int				n;

	if ((n = ls_count_files(dirname)))
	{
		ft_printf("n = %d\n", n);
		files = (char **)malloc(sizeof(char *) * (n + 1));
		//exit(1);
		if ((files = read_files(files, dirname)))
			parse_files(files, n, opt);
	}
	else
		return ;
}

void			ft_ls(t_list *head, t_opt *opt)
{
	t_list *lst;

	lst = head;
	while (lst != NULL)
	{
		if (lst->content_size != 'd')
			ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
	lst = head;
	while (lst != NULL)
	{
		if (lst->content_size == 'd')
			ls_readdir(lst->content, opt);
		lst = lst->next;
	}
}
