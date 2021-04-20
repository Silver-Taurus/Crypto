# Define the C compiler to use
CC 			= 	gcc

# Define the commands to be used
RM 			= 	rm -f

# Define any compile-time flags
CFLAGS 		= 	-Wall -g

# Define any libraries to link into executable
LIBS		=	-lm

# Define any directories containing header files other than /usr/include
INCLUDES	= 	-I./include/

# Define any library paths in addition to /usr/lib
LFLAGS		=

# Define the C source files
SERVER_SRCS = 	src/server.c src/host.c		
CLIENT_SRCS	=	src/client.c src/node.c

# Define the C object files using a Suffix Replacement within a macro.
# Also the gnu make has the default functionality for the Suffix replacement
# from .c to .o
SERVER_OBJS	= 	$(SERVER_SRCS:.c=.o)
CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)

# Define the executable files
SERVER_NAME	=	host
CLIENT_NAME	=	node


# Generic part of Makefile to build any executable file just by
# changing the definitions above
run_server_clean: $(SERVER_NAME) clean_server_files

run_client_clean: $(CLIENT_NAME) clean_client_files

run_server: $(SERVER_NAME)

run_client: $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	gcc $(CFLAGS) $(INCLUDES) -o $(SERVER_NAME) $(SERVER_OBJS) $(LFLAGS) $(LIBS)

$(CLIENT_NAME): $(CLIENT_OBJS)
	gcc $(CFLAGS) $(INCLUDES) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(LFLAGS) $(LIBS)


# Defining an additional functionality of adding cflags and header files to the
# default action of "suffix replacement rule" that changes .c to .o files
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


# Another generic part of the Makefile to clean the build files
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
