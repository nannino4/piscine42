SRCS	= ft_putchar.c ft_strlen.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CLFAGS	= -Wall -Wextra -Werror

%.o : %.c
			gcc -c ${CFLAGS} $< -o $@

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm ${OBJS}

fclean:		clean
			rm ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
