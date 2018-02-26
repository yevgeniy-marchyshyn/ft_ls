/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annulation_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:14:17 by ymarchys          #+#    #+#             */
/*   Updated: 2018/02/13 12:14:19 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	annulation_opt(t_ls *ls)
{
	ls->long_format = 0;
	ls->recursively = 0;
	ls->include_dot = 0;
	ls->rev_lexic = 0;
	ls->sort_mtime = 0;
	ls->indents = 0;
	ls->count_directories = 0;
}
