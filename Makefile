# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarigul <msarigul@student.42kocaeli.com.  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 10:02:09 by msarigul          #+#    #+#              #
#    Updated: 2022/12/28 11:22:39 by msarigul         ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME				:= minishell 

LIBFT				:= ./lib/libft/ft_atoi.c\
							 ./lib/libft/ft_bzero.c\
							 ./lib/libft/ft_calloc.c\
							 ./lib/libft/ft_isalnum.c\
							 ./lib/libft/ft_isalpha.c\
							 ./lib/libft/ft_isascii.c\
							 ./lib/libft/ft_isdigit.c\
							 ./lib/libft/ft_isprint.c\
							 ./lib/libft/ft_itoa.c\
							 ./lib/libft/ft_memchr.c\
							 ./lib/libft/ft_memcmp.c\
							 ./lib/libft/ft_memcpy.c\
							 ./lib/libft/ft_memmove.c\
							 ./lib/libft/ft_memset.c\
							 ./lib/libft/ft_putchar_fd.c\
							 ./lib/libft/ft_putendl_fd.c\
							 ./lib/libft/ft_putnbr_fd.c\
							 ./lib/libft/ft_putstr_fd.c\
							 ./lib/libft/ft_split.c\
							 ./lib/libft/ft_strchr.c\
							 ./lib/libft/ft_strcmp.c\
							 ./lib/libft/ft_strdup.c\
							 ./lib/libft/ft_striteri.c\
							 ./lib/libft/ft_strjoin.c\
							 ./lib/libft/ft_strlcat.c\
							 ./lib/libft/ft_strlcpy.c\
							 ./lib/libft/ft_strlen.c\
							 ./lib/libft/ft_strmapi.c\
							 ./lib/libft/ft_strncmp.c\
							 ./lib/libft/ft_strnstr.c\
							 ./lib/libft/ft_strrchr.c\
							 ./lib/libft/ft_strtrim.c\
							 ./lib/libft/ft_substr.c\
							 ./lib/libft/ft_tolower.c\
							 ./lib/libft/ft_toupper.c\

SRC	 			  := ./src/init/mshell_loop.c\
							 ./src/init/history.c\
							 ./src/parse/ft_parse_pwd.c\
							 ./src/lexer/ft_space_split.c\
							 ./src/lexer/ft_lexer_utils.c\
							 ./src/lexer/check_operations.c\
							 ./src/utils/ft_utils.c\

LREADLINE = -L${HOME}/readline/8.2.1/lib -lreadline

CFLAGS			:= -Wall -Wextra -Werror -I ./inc

all: $(NAME)

$(NAME):
	@gcc ./src/minishell.c $(SRC) $(LIBFT) $(LREADLINE) -o $(NAME) -I ./inc #-g3

clean: fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all

m:
	@./minishell

.PHONY: all re clean fclean m brew readline nvim
