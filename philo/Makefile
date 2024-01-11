NAME = philo

SRCS = philosophers.c utilities.c input_checks.c number_utilities.c

CC = gcc

FLAGS = -Wextra -Wall -Werror -g

OBJS = ${SRCS:.c=.o}

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@ ${CC} ${FLAGS} ${OBJS} -o $@

%.o: %.c
	@ ${CC} ${FLAGS} -c  $< -o $@

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
