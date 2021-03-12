RM 			= 	rm -f
CC 			= 	gcc

NAME 		= 	replace_vowels

CFLAGS 		= 	-Wall
LDFLAGS		= 	-lm

SRCS 		= 	src/dstrings.c 	\
				src/main.c

OBJS		= 	$(SRCS:.c=.o)


run: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) $(LDFLAGS)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

fresh_run: fclean run