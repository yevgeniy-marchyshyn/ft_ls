# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymarchys <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 12:16:06 by ymarchys          #+#    #+#              #
#    Updated: 2018/02/13 12:23:22 by ymarchys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = @gcc
CFLAGS = -Wall -Wextra -Werror -Ilib/includes

FT_LS = main.c\
		annulation_opt.c\
		is_option.c\
		parse_options.c\
		parse_arguments.c\
		ft_ls.c\
		define_type.c\
		sort_ascii_bubble.c\
		parse_files.c\
		recursion_branch.c\
		ls_sort.c\
		skip_dots.c\
		print_dot.c\
		lf.c\
		ls_total.c\
		print_lf.c\
		print_access.c\
		linkpath.c\
		print_files.c\
	    max_size.c\
	    max_links.c\
	    max_len_user.c\
	    max_len_group.c\
	    is_dir.c\
	    lf_not_dirs.c\
	    ls_count_files.c\
	    not_empty_directory.c\
	    link_to_dir.c\
	    ls_read_files.c\
	    ls_dir.c\
	    ls_link.c\

OBJ = $(FT_LS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling libft wait..."
	@make -C ./libft/
	@echo "Compiling ft_ls wait..."
	@gcc -L ./libft/ -lft $(OBJ) -o $(NAME)
	@echo "Done."

clean:
	@make -C ./libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C ./libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

