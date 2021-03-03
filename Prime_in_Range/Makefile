RM 			= 	rm -f
CC 			= 	gcc

NAME 		= 	primes

CFLAGS 		= 	-Wall

SRCS 		= 	src/types.c 	\
				src/primes.c 	\
				src/main.c

OBJS		= 	$(SRCS:.c=.o)


run: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

fresh_run: fclean run