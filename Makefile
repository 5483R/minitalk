FLAGS = -Wall -Wextra -Werror
SRC_CLIENT = client.c
SRC_SERVER = server.c
CC = cc

all : client server 

client : $(SRC_CLIENT)
	@$(CC) $(FLAGS) $(SRC_CLIENT) -o client

server  : $(SRC_SERVER)
	@$(CC) $(FLAGS) $(SRC_SERVER) -o server

clean :
	@rm -f client server

fclean : clean

re: fclean all