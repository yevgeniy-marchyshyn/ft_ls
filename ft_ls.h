/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marchyshyn <ymarchys@student.unit.ua>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:15:12 by marchyshy         #+#    #+#             */
/*   Updated: 2018/02/26 21:13:52 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <dirent.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>

typedef struct			s_ls
{
	int					argc;
	unsigned			long_format : 1;
	unsigned			recursion : 1;
	unsigned			include_dot : 1;
	unsigned			rev_lexic : 1;
	unsigned			sort_mtime : 1;
	unsigned			new_line : 1;
	unsigned			dirs : 1;
	unsigned			handled_args : 1;
	unsigned			error : 1;
	unsigned			attr : 1;
	unsigned			not_sort : 1;
	unsigned			skip_dots : 1;
}						t_ls;

typedef struct stat		t_stat;
typedef struct passwd	t_pw;
typedef struct group	t_group;
typedef struct dirent	t_dir;

int						is_option(char c);
void					annulation_ls(t_ls *ls);
int						parse_options(t_ls *ls, char *argv);
void					parse_arguments(char **argv, int n, t_ls *ls);
void					ft_ls(char **files, t_ls *ls);
char					define_type(t_stat *buf);
void					sort_ascii_bubble(char **file, int n);
void					parse_files(char **files, int n, t_ls *ls, char *path);
void					recursion_branch(char **files, t_ls *ls, char *path);
void					ls_sort(char **files, int n, t_ls *ls, char *path);
int						skip_dots(char *filename);
int						print_dot(char *filename, t_ls *ls);
void					lf(char **files, t_ls *ls, char *path);
void					lf_not_dirs(char **files, t_ls *ls, char *path);
int						ls_total(char **files, t_ls *ls, char *path);
void					print_lf(char *filename, int *w, char *path, t_ls *ls);
char					*access_flags(mode_t st_mode);
char					*linkpath(char *filename);
int						max_links(char **files, t_ls *ls, char *path);
int						max_size(char **files, t_ls *ls, char *path);
int						max_len_user(char **files, t_ls *ls, char *path);
int						max_len_group(char **files, t_ls *ls, char *path);
void					print_files(char **files, t_ls *ls, char *path);
int						is_dir(char *filename, char *path);
int						ls_count_files(char *dirname, char *path);
int						not_empty_directory(char *dirname, t_ls *ls);
int						link_to_dir(char *filename, char *path);
void					ls_dir(char *dirname, t_ls *ls, char *path);
char					**ls_read_files(char **files, char *dirname);
void					ls_link(char *linkname, t_ls *ls, char *path);
int						timecmp(char *file1, char *file2, char *path);
int						print_lf_p1(t_stat *buf, char *path);
void					print_lf_p2(t_stat *buf, t_pw *pw, t_group *gr, int *w);
void					print_lf_p3(char *path, char *f, \
char *tmp, t_stat *buf);
int						print_lf_p4(char *path);

#endif
