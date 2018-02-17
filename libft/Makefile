# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 14:42:31 by ymarchys          #+#    #+#              #
#    Updated: 2018/02/13 12:16:19 by ymarchys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iincludes

FT_PRINTF = ft_printf.c\
		./ft_printf/check_flags_modif.c\
        ./ft_printf/active_bits.c\
        ./ft_printf/m_putchar.c\
        ./ft_printf/m_putstr.c\
        ./ft_printf/annulation.c\
		./ft_printf/set_to_zero.c\
        ./ft_printf/is_parse_char.c\
        ./ft_printf/is_flag_mod.c\
        ./ft_printf/is_modificator.c\
        ./ft_printf/is_type.c\
        ./ft_printf/ibs.c\
        ./ft_printf/ibs_uns.c\
        ./ft_printf/put_percent.c\
		./ft_printf/put_dec.c\
        ./ft_printf/modificator_dec.c\
		./ft_printf/put_unsigned.c\
		./ft_printf/modificator_uns.c\
        ./ft_printf/put_lc.c\
        ./ft_printf/count_bytes.c\
        ./ft_printf/put_c.c\
        ./ft_printf/put_s.c\
        ./ft_printf/put_ls.c\
        ./ft_printf/putstr_ls.c\
        ./ft_printf/strlen_ls.c\
		./ft_printf/put_hex.c\
		./ft_printf/modificator_hex.c\
		./ft_printf/put_octal.c\
		./ft_printf/modificator_octal.c\
		./ft_printf/put_p.c\
		./ft_printf/put_unknown_type.c\
		./ft_printf/put_padding.c\
		./ft_printf/prec_diff.c\
		./ft_printf/put_float.c\
		./ft_printf/put_binary.c\
		./ft_printf/if_color.c\
		./ft_printf/color_off.c\

LIBFT = ft_memset.c\
		ft_bzero.c\
 		ft_memcpy.c\
 		ft_memccpy.c\
 		ft_memmove.c\
 		ft_memchr.c\
 		ft_memcmp.c\
 		ft_strlen.c\
 		ft_strdup.c\
 		ft_strcpy.c\
 		ft_strncpy.c\
 		ft_strcat.c\
 		ft_strncat.c\
 		ft_strlcat.c\
 		ft_strchr.c\
 		ft_strrchr.c\
 		ft_strstr.c\
 		ft_strnstr.c\
 		ft_strcmp.c\
 		ft_strncmp.c\
 		ft_atoi.c\
 		ft_isalpha.c\
 		ft_isdigit.c\
 		ft_isalnum.c\
 		ft_isascii.c\
 		ft_isprint.c\
 		ft_toupper.c\
 		ft_tolower.c\
 		ft_memalloc.c\
 		ft_memdel.c\
 		ft_strnew.c\
 		ft_strdel.c\
 		ft_strclr.c\
 		ft_striter.c\
 		ft_striteri.c\
 		ft_strmap.c\
 		ft_strmapi.c\
 		ft_strequ.c\
 		ft_strnequ.c\
 		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstascii.c\
		ft_lst_push_back.c\
		ft_power.c\
		ft_strsplit.c\
		ft_itoa.c\
		get_next_line.c\


LIBFT_OBJ = $(LIBFT:.c=.o)

FT_PRINTF_OBJ = $(FT_PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(FT_PRINTF_OBJ) $(LIBFT_OBJ)
	ar rc $(NAME) $(FT_PRINTF_OBJ) $(LIBFT_OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(FT_PRINTF_OBJ) $(LIBFT_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
