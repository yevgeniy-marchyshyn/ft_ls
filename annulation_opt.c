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

void	annulation_opt(t_opt *opt)
{
	opt->long_format = 0;
	opt->recursively = 0;
	opt->include_dot = 0;
	opt->rev_lexic = 0;
	opt->sort_mtime = 0;
}
