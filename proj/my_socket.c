#include "my_socket.h"

SOCKET create_socket(void)
{
   SOCKET s;
   s = socket(AF_LOCAL, SOCK_STREAM, 0);
   if (s < 0)
   {
      printf("Failed to create a socket.\n");
      exit(-1);
   }
   return (s);
}
char *get_path()
{
   char *path;
   path = getenv("SVROOT");
   strcat(path, "cmd");
   return (path);
}
