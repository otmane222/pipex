NAME = pipex
NAME_BNS = pipex_bonus

PRINTF = libftprintf.a

SRCS = pipex.c \
	pipex_utils1.c \
	pipex_utils2.c \
	pipex_utils_mandatory.c \

BNS_SRCS	= pipex_bonus.c \
			pipex_utils1_bonus.c \
			pipex_utils2_bonus.c \
			pipex_utils3_bonus.c \
			pipex_utils4_bonus.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c \

INCL = pipex.h 

OBJS = ${SRCS:%.c=%.o}

BNS_OBJS	= ${BNS_SRCS:%.c=%.o}

FLAGS = -Wall -Wextra -Werror

CC = cc

all: ${NAME}

$(NAME): ${OBJS}
	$(CC) -o $@ ${OBJS} 

%_bonus.o : %_bonus.c pipex_bonus.h get_next_line.h ft_printf.h
	$(CC) -c $(FLAGS) $<

%.o : %.c $(INCL)
	$(CC) -c $(FLAGS) $<

bonus: ft_printf_rule ${NAME_BNS} 

${NAME_BNS}: ${BNS_OBJS} 
	$(CC) -o ${NAME_BNS}  ${BNS_OBJS} ft_printf/libftprintf.a

ft_printf_rule:
	@make -C ft_printf
	
clean:
	rm -f $(OBJS) $(BNS_OBJS)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME) ${NAME_BNS} ft_printf/libftprintf.a

re: fclean all

.PHONY: all bonus clean fclean re