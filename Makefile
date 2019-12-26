# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 12:48:13 by lpellier          #+#    #+#              #
#    Updated: 2019/11/30 11:53:38 by lpellier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRCS =	./ft_printf.c \
		./ft_fill_struct.c \
		./ft_output.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)

clean :
	@rm -rf $(OBJS)
	@make clean -C libft

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C libft

re : fclean all