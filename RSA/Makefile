RM 		= rm -f
CC 		= gcc

NAME 	= rsa

SRCS 	= src/modulars.c	\
		src/primes.c		\
		src/rsa.c			\
		src/main.c

OBJS 	= $(SRCS:.o=.out)


all: $(OBJS)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all