RM 		= rm -f
CC 		= gcc

NAME 	= rsa

CFLAGS		= -Iinclude/ -W -Wall -Wextra -march=native -ggdb3

SRCS 	= src/modulars.c	\
		src/primes.c		\
		src/rsa.c			\
		src/main.c

OBJS 	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lm

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

re_clean: fclean all clean