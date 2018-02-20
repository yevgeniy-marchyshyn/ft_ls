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
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <time.h>

typedef struct		ls
{
	unsigned char	long_format;
	unsigned char	recursively;
	unsigned char	include_dot;
	unsigned char	rev_lexic;
	unsigned char	sort_mtime;
	unsigned char	indents;
	unsigned char	first_directory;
}					t_ls;

//typedef struct		long_format
//{
//	quad_t			sum;
//	nlink_t			hard_links;
//	char 			*username;
//	char 			*groupname;
//	size_t			size;
//	time_t			lst_mtime;
//}					t_lf;

int				is_option(char c);
void			annulation_opt(t_ls *ls);
int				parse_options(t_ls *ls, char *argv);
void			parse_arguments(char **argv, int n, t_ls *ls);
void			ft_ls(t_list *head, t_ls *ls);
char			define_type(struct stat *buf);
void			sort_ascii_bubble(char **file, int n);
void			parse_files(char **files, t_ls *ls, char *path);
void			ft_ls_recursion(t_list *head, t_ls *ls, char *path);
void			ls_sort(char **files, int n, t_ls *ls);
int				skip_dots(void *content);
int 			print_dot(void *content, t_ls *ls);
quad_t			ls_total_lst(t_list *head);
void			long_format(char **files, int n, t_ls *ls);
quad_t			ls_total(char **files, int n, t_ls *ls);
void			access_flag(int value);
//void			lf_lst(t_list *head);

# endif
