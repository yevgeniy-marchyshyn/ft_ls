/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:25:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/16 19:25:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		sort_ascii_bubble(char **file, int n)
{
	char 	*tmp;
	int		i;
	int 	k;

	i = 0;
	k = 0;
	while (k < n)
	{
		i = 0;
		while (file[i])
		{
			if (file[i + 1] && ft_strcmp(file[i], file[i + 1]) > 0)
			{
				tmp = file[i];
				file[i] = file[i + 1];
				file[i + 1] = tmp;
			}
			i++;
		}
		k++;
	}
}

void		parse_files(char **argv, int n, t_opt *opt)
{
	struct stat		buf;
	char			**files;
	t_list			*head;
	t_list			*elem;
	int				i;
	int 			k;

	i = 0;
	head = NULL;
	files = (char**)malloc(sizeof(char*) * (n + 1));
	while (*argv)
		files[i++] = *argv++;
	files[i] = NULL;
	sort_ascii_bubble(files, n);
	k = 0;
	while (files[k])
	{
		if (lstat(files[k], &buf) == -1)
		{
			ft_printf("ft_ls: ");
			perror(files[k]);
		}
		else
		{
			elem = ft_lstnew(files[k], define_type(&buf));
			ft_lst_push_back(&head, elem);
		}
		k++;
	}
	t_list *lst;
	lst = head;
//	while (lst != NULL)
//	{
//		ft_printf("%s has type '%c'");
//		lst = lst->next;
//	}
	ft_ls(head, opt);
}
