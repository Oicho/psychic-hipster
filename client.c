#include "my_socket.h"
#include  "ctl_parse.h"

int close_server(SOCKET listen_sock)
{
   int len;
   len = strlen("quit");
   write(listen_sock, &len, sizeof(len));
   write(listen_sock, "quit", len);
   close(listen_sock);
   printf("closed\n");
   return (0);
}
int main(int  argc,
	 char **argv)
{
   SOCKET              listen_sock;
   struct sockaddr_un  addr;
   union conv_sockaddr u_sock_addr;
   int                 len, nb_str;
   char                **print_me;
   listen_sock = create_socket();
   strcpy(addr.sun_path, get_path());
   addr.sun_family = AF_LOCAL;
   u_sock_addr.un = &addr;
   if (connect(listen_sock, u_sock_addr.ad, sizeof(addr)) == -1)
   {
      printf("Client not connected.\n");
      return (-1);
   }
   if ((nb_str =parse_arg(argc, argv, &print_me)) == 0)
      return (close_server(listen_sock));
   for (; nb_str > 0; nb_str--)
   {
      len = strlen(print_me[nb_str - 1]);
      write(listen_sock, &len, sizeof(len));
      write(listen_sock, print_me[nb_str - 1], len);
   }
   close(listen_sock);
   free(print_me);
   return (0);
}
