/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:53:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/18 17:53:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			**fill_files(char **argv, int n)
{
	char	**files;
	int		i;

	i = 0;
	files = (char**)malloc(sizeof(char*) * (n + 1));
	while (*argv)
		files[i++] = *argv++;
	files[i] = NULL;
	sort_ascii_bubble(files, n);
	return (files);
}

void				parse_arguments(char **argv, int n, t_ls *ls)
{
	struct stat		buf;
	char			**files;
	t_list			*head;
	t_list			*elem;
	int 			i;

	i = 0;
	head = NULL;
	files = fill_files(argv, n);
	while (files[i])
	{
		if (lstat(files[i], &buf) == -1)
		{
			write(2, "ft_ls: ", 7);
			perror(files[i]);
			ls->indents = 1;
		}
		else
		{
			elem = ft_lstnew(files[i], (size_t)define_type(&buf));
			ft_lst_push_back(&head, elem);
		}
		i++;
	}
//	ls_list_sort(head, ls);
	ft_ls(head, ls);
}