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
		perror(dirname);
		return (n);
	}
	if (dir)
	{
		while ((sd = readdir(dir)) != NULL)
			n++;
	}
	closedir(dir);
	return (n);
}

static char		**read_files(char **files, char *dirname, int n)
{
	DIR					*dir;
	struct dirent		*sd;
	int 				i;

	i = 0;
	dir = opendir(dirname);
	while ((sd = readdir(dir)) != NULL)
	{
		files[i] = ft_strdup(sd->d_name);
		i++;
	}
	files[i] = NULL;
	sort_ascii_bubble(files, n);
	closedir(dir);
	return (files);
}

static void		ls_readdir(char *dirname, t_opt *opt)
{
	char			**files;
	int				n;
	int 			i;

	if ((n = ls_count_files(dirname)))
	{
		files = (char **)malloc(sizeof(char *) * (n + 1));
		files = read_files(files, dirname, n);
		if (opt->recursively)
			parse_files2(dirname, files, opt);
		else
		{
			i = 0;
			while (i < n)
			{
				if ((ft_strcmp(files[i], ".") == 0 ||
						ft_strcmp(files[i], "..") == 0 || files[i][0] == '.') && !opt->include_dot)
					i++;
				else
					ft_printf("%s\n", files[i++]);
			}
		}
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
		{
			ft_printf("\n%s:\n", lst->content);
			ls_readdir(lst->content, opt);
		}
		lst = lst->next;
	}
}
