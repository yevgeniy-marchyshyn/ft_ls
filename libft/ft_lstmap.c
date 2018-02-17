/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:02:43 by ymarchys          #+#    #+#             */
/*   Updated: 2017/11/07 15:30:41 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lstresult;
	t_list *lstmove;

	if (lst && f)
	{
		lstresult = f(lst);
		lstmove = lstresult;
		while (lst->next)
		{
			lstmove->next = f(lst->next);
			lstmove = lstmove->next;
			lst = lst->next;
		}
		return (lstresult);
	}
	return (NULL);
}
