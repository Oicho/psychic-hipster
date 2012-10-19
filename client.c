#include "my_socket.h"

int main(int  argc,
	 char **argv)
{
   SOCKET              listen_sock;
   struct sockaddr_un  addr;
   union conv_sockaddr u_sock_addr;
   int                 len, nb_str;
   char                **print_me;
   listen_sock = create_socket();
   printf("Socket sucessfully created.\n");
   strcpy(addr.sun_path, get_path());
   printf("Path set.\n");
   addr.sun_family = AF_LOCAL;
   u_sock_addr.un = &addr;
   connect(listen_sock, u_sock_addr.ad, sizeof(addr));
   printf("Client connected.\n");
   for (nb_str = parse_arg(argc, argv, print_me); nb_str > 0; nb_str--)
   {
      len = strlen(print_me[nb_str - 1]);
      write(listen_sock,&len, sizeof(len));
      write(listen_sock, print_me[nb_str - 1], len);
   }
   close(listen_sock);
   return (0);
}
