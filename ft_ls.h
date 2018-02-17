/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marchyshyn <ymarchys@student.unit.ua>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:15:12 by marchyshy         #+#    #+#             */
/*   Updated: 2018/02/14 13:44:46 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

#include "./libft/libft.h"
#include "./libft/ft_printf/ft_printf.h"
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>

typedef struct		indents
{
	unsigned char	file;
	unsigned char	dir;
}					f_indents;

typedef struct		opt
{
	unsigned char	long_format;
	unsigned char	recursively;
	unsigned char	include_dot;
	unsigned char	rev_lexic;
	unsigned char	sort_mtime;
	unsigned char	hyphen_file;
	f_indents		f;

}					t_opt;

int				is_option(char c);
void			annulation_opt(t_opt *opt);
int				parse_options(t_opt *opt, char *argv);
void			parse_files(char **argv, int n, t_opt *opt);
void			ft_ls(t_list *head, t_opt *opt);
char			define_type(struct stat *buf);
//void			is_error(t_list **head);
//void			ft_ls(t_list *head, t_opt *opt);
//void			indents(t_list *head, t_opt *opt);

# endif
