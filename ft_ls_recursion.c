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
		{
			n++;
		}
	closedir(dir);
	return (n);
}

static char		**read_files(char **files, char *path, int n)
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

static void		ls_readdir(char *dirname, t_opt *opt, char *path)
{
	char			**files;
	char 			*path2;
	int				n;
	int 			i;

	path2 = ft_strjoin(path, "/");
	if ((n = ls_count_files(dirname, path)))
	{
		files = (char **)malloc(sizeof(char *) * (n + 1));
		files = read_files(files, ft_strjoin(path2, dirname), n);
		if (opt->recursively)
			parse_files(files, opt, ft_strjoin(path2, dirname));
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

void			ft_ls_recursion(t_list *head, t_opt *opt, char *path)
{
	t_list	*lst;

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
			ls_readdir(lst->content, opt, path);
		}
		lst = lst->next;
	}
}
