#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "print_helps"

char *create_str(char c)
{
   char *ret = malloc(3);

   ret[0] = '-';
   ret[1] = c;
   ret[2] = ' ';
   return (ret);
}

void parse_value(int  input_char,
		 char **larg,
		 int nb_arg)
{
   char *acc;

   switch (input_char)
   {
      case 'a':
      case 'o':
	 if (nb_arg != 0)
	    printf("Invalid argument placement.\nUse --help.\n");
      default :
      {
	 acc = create_str(input_char);
	 strcat(*larg, acc);
	 free(acc);
      }
      break;
   }
}
int concat_svname(int  argc,
		  char **argv,
		  int  pos,
		  char *larg,
		  char ***print_me)
{
   int nb_arg = argc - pos;
   *print_me = malloc(sizeof(char) * nb_arg * 200);
   for (int i = 0; pos < argc; ++pos)
   {
      *print_me[i] = larg;
      *print_me[i] = strcat(*print_me[i], argv[pos]);
      i++;
   }
   return (nb_arg);
}

int parse_arg(int  argc,
	       char **argv,
	       char ***print_me)
{
   char       input_char;
   int        nb_arg;
   extern int opterr;
   char       *format = "qouhkrda";
   char       *larg = malloc(40);

   nb_arg = 0;
   opterr = 1;
   if ((argc == 2) && (!strcmp(argv[1], "--help")))
   {
      printf("help\n");
      return (0);
   }
   while ((input_char = getopt(argc, argv, format)) != -1)
   {
      if (input_char == 'q')
      {
	 free(larg);
	 return (0);
      }
      parse_value(input_char, &larg, nb_arg);
      nb_arg++;
   }
   return (concat_svname(argc, argv, optind, larg, print_me));
}
