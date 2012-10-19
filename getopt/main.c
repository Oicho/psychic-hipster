#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc,
	 char **argv)
{
   char       input_char;
   int        nb_arg;
   extern int opterr;
   char       *format = "ouhkrda";
   char       larg[7];
   for (nb_arg = 0; nb_arg < 7; nb_arg ++)
   {
      larg[nb_arg] = ' ';
   }
   opterr = 1;
   nb_arg = 0;
   if ((argc == 2) && (!strcmp(argv[1], "--help")))
   {
      printf("help\n");
      return (0);
   }
   while ((input_char = getopt(argc, argv, format)) != -1)
   {
      switch (input_char)
      {
	 case 'a':
	    printf("a");
	    break;
	 default :
	 {
	    larg[nb_arg] = input_char;
	    nb_arg++;
	 }
	    break;
      }
   }
   printf("list arg = %s", larg);
}
