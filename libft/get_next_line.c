/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:54:35 by ymarchys          #+#    #+#             */
/*   Updated: 2017/12/11 18:25:34 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		form_a_string(ssize_t n, char *buff, char **line, t_list *lst)
{
	int i;

	i = 0;
	if (!n && !(ft_strlen(lst->content)))
		return (0);
	if (n == -1)
		return (-1);
	while (((char*)lst->content)[i] != '\n' && ((char*)lst->content)[i])
		i++;
	*line = ft_strsub(lst->content, 0, i);
	buff = ft_strdup(lst->content + ++i);
	if (lst->content)
		ft_bzero(((char*)lst->content), ft_strlen(lst->content));
	ft_strdel((char**)&lst->content);
	lst->content = buff;
	return (*line ? 1 : 0);
}

static int		read_a_buffer(const int fd, t_list *lst, char **line)
{
	char		*buff;
	char		*tmp;
	ssize_t		n;
	int			i;

	i = 0;
	buff = ft_strnew(BUFF_SIZE + 1);
	while ((n = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[n] = '\0';
		if (!lst->content)
			lst->content = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(lst->content, buff);
			if (lst->content)
				ft_bzero(((char*)lst->content), ft_strlen(lst->content));
			ft_strdel((char**)&lst->content);
			lst->content = tmp;
		}
		if (ft_strchr(lst->content, '\n'))
			break ;
	}
	ft_strdel(&buff);
	return (form_a_string(n, buff, line, lst));
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*lst;

	if (fd < 0 || line == NULL)
		return (-1);
	lst = head;
	if (head)
	{
		while (lst != NULL)
		{
			if (fd == (const int)lst->content_size)
				break ;
			lst = lst->next;
		}
	}
	if (!lst)
	{
		lst = ft_lstnew(NULL, 0);
		ft_lstadd(&head, lst);
		lst->content_size = fd;
	}
	return (read_a_buffer(fd, lst, line));
}
