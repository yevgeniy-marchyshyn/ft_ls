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

typedef struct			s_ls
{
	unsigned char		long_format;
	unsigned char		recursively;
	unsigned char		include_dot;
	unsigned char		rev_lexic;
	unsigned char		sort_mtime;
	int					indents;
	int					count_directories;
}						t_ls;

typedef struct stat		t_stat;
typedef struct passwd	t_pw;
typedef struct group	t_group;

int						is_option(char c);
void					annulation_opt(t_ls *ls);
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
int						lf_not_dirs(char **files, t_ls *ls, char *path);
int						ls_total(char **files, t_ls *ls, char *path);
void					print_lf(char *filename, int *w, char *path);
void					print_access(mode_t st_mode);
char					*linkpath(char *filename);
int						max_links(char **files, char *path);
int						max_size(char **files, char *path);
int						max_len_user(char **files, char *path);
int						max_len_group(char **files, char *path);
int						print_files(char **files, t_ls *ls, char *path);
int						is_dir(char *filename, char *path);
int						ls_count_files(char *dirname, char *path);
int						not_empty_directory(char *dirname, t_ls *ls);
int						link_to_dir(char *filename, char *path);
void					ls_dir(char *dirname, t_ls *ls, char *path);
char					**ls_read_files(char **files, char *dirname);
void					ls_link(char *linkname, t_ls *ls, char *path);

#endif
