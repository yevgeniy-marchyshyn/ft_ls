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
		while ((sd = readdir(dir)) != NULL)
			n++;
	closedir(dir);
	return (n);
}

static char		**ls_read_files(char **files, char *dirname, int n)
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

static void		ls_dir_ext(t_ls *ls, char **files, char *path, int n)
{
	int i;

	if (ls->recursively)
		parse_files(files, ls, path);
	else
	{
		i = 0;
		if (ls->include_dot)
			while (i < n)
				ft_printf("%s\n", files[i++]);
		else
		{
			while (i < n)
			{
				if (files[i][0] != '.')
					ft_printf("%s\n", files[i]);
				i++;
			}
		}
	}
}

static void		ls_dir(char *dirname, t_ls *ls, char *path)
{
	char			**files;
	int				n;

	path = ft_strjoin(dirname, "/");
	if ((n = ls_count_files(dirname)))
	{
		files = (char **)malloc(sizeof(char *) * (n + 1));
		files = ls_read_files(files, dirname, n);
		ls_sort(files, n, ls);
		ls_dir_ext(ls, files, path, n);
	}
}

void			ft_ls(t_list *head, t_ls *ls)
{
	t_list	*lst;
	char 	*path;

	lst = head;
	path = NULL;
	while (lst != NULL)
	{
		if (lst->content_size != 'd')
		{
			ft_printf("%s\n", lst->content);
			ls->indents = 1;
		}
		lst = lst->next;
	}
	lst = head;
	while (lst != NULL)
	{
		if (lst->content_size == 'd')
		{
			ls->indents ? ft_printf("\n") : 0;
			ls->first_directory || ls->indents ?
			ft_printf("%s:\n", lst->content) : 0;
			ls->first_directory = 1;
			ls_dir(lst->content, ls, path);
		}
		lst = lst->next;
	}
}
