NAME = pipex

SRCS = pipex.c \
	pipex_utils1.c \
	pipex_utils2.c \
	pipex_utils.c \

BNS_SRCS	= pipex_bonus.c \
			pipex_utils1.c \
			pipex_utils2.c \
			pipex_utils3bonus.c \
			pipex_utils4bonus.c \
			get_next_line.c \
			get_next_line_utils.c \

INCL = pipex.h

OBJS = ${SRCS:%.c=%.o}

BNS_OBJS	= ${BNS_SRCS:%.c=%.o}

FLAGS = -Wall -Wextra -Werror

CC = cc

all: ${NAME}

$(NAME): ${OBJS}
	$(CC) -o $@ ${OBJS} 

BNS_OBJS : %.c 
	$(CC) -c $(FLAGS) $<

%.o : %.c $(INCL)
	$(CC) -c $(FLAGS) $<

bonus: ${BNS_OBJS} pipex_bonus.h get_next_line.h
	$(CC) -o ${NAME} ${BNS_OBJS} 

clean:
	rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
