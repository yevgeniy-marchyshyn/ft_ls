/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marchyshyn <ymarchys@student.unit.ua>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 22:26:23 by marchyshy         #+#    #+#             */
/*   Updated: 2018/02/18 22:26:40 by marchyshy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ls_count_files(char *dirname, char *path)
{
	DIR				*dir;
	struct dirent	*sd;
	int 			n;

	n = 0;
	dir = opendir(path);
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

static char		**ls_fill_files(char **files, char *path, int n)
{
	DIR					*dir;
	struct dirent		*sd;
	int 				i;

	i = 0;
	dir = opendir(path);
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

static void		ls_readdir(char *dirname, t_ls *ls, char *path)
{
	char			**files;
	char 			*path2;
	char 			*path3;
	int				n;
	int 			i;

	path2 = ft_strjoin(path, dirname);
	path3 = ft_strjoin(path2, "/");
	if ((n = ls_count_files(dirname, path3)))
	{
		files = (char **)malloc(sizeof(char *) * (n + 1));
		files = ls_fill_files(files, path3, n);
		if (ls->recursively)
			parse_files(files, ls, path3);
		else
		{
			i = 0;
			while (i < n)
					ft_printf("%s\n", files[i++]);
		}
	}
	else
		return ;
}

void			ft_ls_recursion(t_list *head, t_ls *ls, char *path)
{
	t_list	*lst;

	lst = head;
	while (lst != NULL)
	{
//		if ((ls->include_dot && ((char*)lst->content)[0] == '.') ||
//				((char*)lst->content)[0] != '.')
		if (print_dot(lst->content, ls))
			ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
	lst = head;
	while (lst != NULL)
	{
		if (lst->content_size == 'd' && skip_dots(lst->content))
//		if (lst->content_size == 'd' && ft_strcmp(lst->content, ".") != 0 &&
//				ft_strcmp(lst->content, "..") != 0)
		{
//			if ((ls->include_dot && ((char*)lst->content)[0] == '.') ||
//					((char*)lst->content)[0] != '.')
			if (print_dot(lst->content, ls))
			{
				ft_printf("\n%s%s:\n", path, lst->content);
				ls_readdir(lst->content, ls, path);
			}
		}
		lst = lst->next;
	}
}
