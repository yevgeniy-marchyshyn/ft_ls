/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_print_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:55:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/22 12:55:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		no_error_to_print_total(t_list *head, t_ls *ls, char *path)
{
	t_list			*lst;
	struct passwd	*pw;
	struct group	*gr;
	char 			*path2;
	char 			*path3;

	lst = head;
	if (path != NULL)
	{

	}
//	if (path != NULL)
//	{
//		path2 = ft_strjoin(path, "/");
//		path3 = ft_strjoin(path2, filename);
//		lstat(path3, &buf);
//	}
//	else
//		lstat(filename, &buf);
//	if (!(pw = getpwuid(buf.st_uid)))
//		return ;
//	if (!(gr = getgrgid(buf.st_gid)))
//		return ;
	while (lst != NULL)
	{

	}
}

void			lf_print_files(t_list *head, t_ls *ls, char *path)
{
	t_list	*lst;
	int 	w[4];
	int 	total;

	lst = head;
	w[0] = max_links_lst(head, path);
	if ((w[1] = max_len_user_lst(head, path)) == -1)
		return ;
	if ((w[2] = max_len_group_lst(head, path)) == -1)
		return ;
	w[3] = max_size_lst(head, path);
	if (no_error_to_print_total(head, ls, path))
		ft_printf("%zd\n", ls_total_lst(head, ls, path));
	while (lst != NULL)
	{
		if ((lst->content_size != 'd' || ls->recursively) &&
				print_dot(lst->content, ls))
		{
			print_long_format(lst->content, w, path);
			ls->indents = 1;
		}
		lst = lst->next;
	}
}
