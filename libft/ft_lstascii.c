/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marchyshyn <ymarchys@student.unit.ua>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 01:51:32 by marchyshy         #+#    #+#             */
/*   Updated: 2018/02/13 01:54:06 by marchyshy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstascii(t_list *head)
{
	t_list	*p;
	char	*tmp_content;
	size_t	tmp_content_size;

	p = head;
	while (p->next != NULL)
	{
		if (ft_strcmp(p->content, p->next->content) > 0)
		{
			tmp_content = ft_strdup((char*)p->content);
			tmp_content_size = p->content_size;
			ft_memdel(&p->content);
			p->content = ft_strdup((char*)p->next->content);
			p->content_size = p->next->content_size;
			ft_memdel(&p->next->content);
			p->next->content = ft_strdup(tmp_content);
			p->next->content_size = tmp_content_size;
			ft_strdel(&tmp_content);
			p = head;
			continue ;
		}
		p = p->next;
	}
}
