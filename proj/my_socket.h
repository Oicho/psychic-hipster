#ifndef MY_SOCKET_H_
# define MY_SOCKET_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


typedef int SOCKET;
union conv_sockaddr
{
   struct sockaddr_un *un;
   struct sockaddr    *ad;
};

SOCKET create_socket(void);
char *get_path();

#endif /* !MY_SOCKET_H_ */
