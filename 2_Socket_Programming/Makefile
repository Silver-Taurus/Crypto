RM 			= 	rm -f
CC 			= 	gcc

SERVER_NAME	=	host
CLIENT_NAME	=	node

CFLAGS 		= 	-Wall
LDFLAGS		=

SERVER_SRCS = 	src/server.c 	\
				src/host.c		
CLIENT_SRCS	=	src/client.c 	\
				src/node.c

SERVER_OBJS	= 	$(SERVER_SRCS:.c=.o)
CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)


run_server: $(SERVER_NAME)

run_client: $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	gcc -o $(SERVER_NAME) $(SERVER_OBJS) $(LDFLAGS)

$(CLIENT_NAME): $(CLIENT_OBJS)
	gcc -o $(CLIENT_NAME) $(CLIENT_OBJS) $(LDFLAGS)

fclean: fclean_server fclean_client

fclean_server: clean_server_files
	$(RM) $(SERVER_NAME)

fclean_client: clean_client_files
	$(RM) $(CLIENT_NAME)

clean_files: clean_server_files clean_client_files

clean_server_files:
	$(RM) $(SERVER_OBJS)

clean_client_files:
	$(RM) $(CLIENT_OBJS)
