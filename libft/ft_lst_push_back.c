/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:07:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/16 18:07:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **head, t_list *lst)
{
	t_list *current;

	current = *head;
	if (!current)
		*head = lst;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = lst;
		lst->next = NULL;
	}
}
