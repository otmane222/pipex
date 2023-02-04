# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:42:01 by oaboulgh          #+#    #+#              #
#    Updated: 2022/11/04 17:19:15 by oaboulgh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c \
			  ft_puts.c \
			  ft_format.c \
			  
			  

OBJS		= $(SRCS:%.c=%.o)

INCS		= ft_printf.h

FLAGS		= -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c $(INCS)
	cc $(FLAGS) -c $<

$(NAME):$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean