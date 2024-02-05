NAME = philo

SRCS = philosophers.c utilities.c input_checks.c number_utilities.c ft_split.c philo_init.c ft_routine.c utilities_plus.c threads.c monitor.c

HEADER = philo.h

CC = gcc

FLAGS = -Wextra -Wall -Werror -g -pthread

OBJS = ${SRCS:.c=.o}

RM = rm -rf

all: ${NAME} ${HEADER}

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
