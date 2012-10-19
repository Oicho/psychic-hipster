#include "my_socket.h"

int server(SOCKET client_sock)
{

   int  l;
   char *str;
   printf("Message\n");
   while (42)
   {
      if (!read(client_sock, &l, sizeof(int)))
	 return (0);
      str = malloc(sizeof(l));
      read(client_sock, str, l);
      printf("%s\n",str);
      if (!strcmp(str, "quit"))
	 return (1);
      free(str);
   }
}
int main(void)
{
   SOCKET              listen_sock,client_sock;
   struct sockaddr_un  addr_client, addr_server;
   union conv_sockaddr u_sockaddr;
   socklen_t           client_name_len;
   int                 quit_msg;
   char                *path;
   path = get_path();
   unlink(path);
   listen_sock = create_socket();
   strcpy(addr_server.sun_path, path);
   addr_server.sun_family = AF_LOCAL;
   u_sockaddr.un = &addr_server;
   bind(listen_sock, u_sockaddr.ad, sizeof(addr_server));
   printf("begin listen\n");
   listen(listen_sock, 5);
   printf("listen end\n");
   do
   {
      /* Accept a connection.   */
      u_sockaddr.un = &addr_client;
      client_sock = accept(listen_sock, u_sockaddr.ad, &client_name_len);
      /* Handle the connection.   */
      quit_msg= server(client_sock);
      /* Close our end of the connection.   */
      close (client_sock);
   } while (!quit_msg);
   /* Remove the socket file.   */
   close (listen_sock);
   unlink (path);
   return 0;
}
