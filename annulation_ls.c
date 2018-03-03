/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annulation_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 15:52:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/03 15:52:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	annulation_ls(t_ls *ls)
{
	ls->long_format = 0;
	ls->recursion = 0;
	ls->include_dot = 0;
	ls->rev_lexic = 0;
	ls->sort_mtime = 0;
	ls->new_line = 0;
	ls->dirs = 0;
	ls->argc = 0;
	ls->handled_args = 0;
	ls->error = 0;
}
