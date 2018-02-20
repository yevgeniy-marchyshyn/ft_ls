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

FLAGS = -Wall -Wextra -Werror -o

LIBRARY = libft.a

FT_LS = main.c\
		annulation_opt.c\
		is_option.c\
		parse_options.c\
		parse_arguments.c\
		ft_ls.c\
		define_type.c\
		sort_ascii_bubble.c\
		parse_files.c\
		ft_ls_recursion.c\
		ls_sort.c\
		skip_dots.c\
		print_dot.c\
		ls_total_lst.c\

all: $(NAME)

$(NAME):
	cd libft && make && mv libft.a .. && cd ..
	gcc $(FLAGS) $(NAME) $(LIBRARY) $(FT_LS)

clean:
	cd libft && make clean && cd ..

fclean: clean
	cd libft && make fclean & cd ..
	/bin/rm -f $(NAME)

re: fclean all

