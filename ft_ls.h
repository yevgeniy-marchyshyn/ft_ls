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

int				is_option(char c);
void			annulation_opt(t_ls *ls);
int				parse_options(t_ls *ls, char *argv);
void			parse_arguments(char **argv, int n, t_ls *ls);
void			ft_ls(char **files, t_ls *ls);
char			define_type(struct stat *buf);
void			sort_ascii_bubble(char **file, int n);
void			parse_files(char **files, int n, t_ls *ls, char *path);
void			ft_ls_recursion(char **files, t_ls *ls, char *path);
void			ls_sort(char **files, int n, t_ls *ls, char *path);
int				skip_dots(char *filename);
int 			print_dot(char *filename, t_ls *ls);
void			long_format(char **files, t_ls *ls, char *path);
unsigned char	long_format_not_dirs(char **files, t_ls *ls, char *path);
int				ls_total(char **files, t_ls *ls, char *path);
void			access_flag(int value);
void			print_long_format(char *filename, int *w, char *path);
void			print_access(mode_t st_mode);
char 			*time_format(time_t n);
char			*linkpath(char *filename);
int 			max_links(char **files);
int 			max_size(char **files);
int 			max_len_user(char **files);
int 			max_len_group(char **files);
void			print_files(char **files, t_ls *ls);
int				is_dir(char *filename);
int				ls_count_files(char *dirname, char *path);
int 			not_empty_directory(char *dirname, t_ls *ls);

# endif
