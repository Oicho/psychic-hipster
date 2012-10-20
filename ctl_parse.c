#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "print_helps"

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
   printf("%c\n", input_char);
   switch (input_char)
   {
      case 'a':
      case 'o':
	 if (nb_arg != 0 && !((*larg)[0] != 'a' || (*larg)[0] != 'o'))
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
char** concat_svname(int  argc,
		     char **argv,
		     int  pos,
		     char *larg,
		     int *nb_arg)

{
   int nb_a = argc - pos;
   char **print_me;
   printf("we have %d arg\n", nb_a);
   print_me = malloc(sizeof(char) * nb_a);
   for (int i = 0; i < nb_a; i++)
   {
      print_me[i] = malloc(200);
      strcpy(print_me[i], larg);
      strcat(print_me[i], argv[pos]);
      pos++;
   }
   *nb_arg = nb_a;
   return (print_me);
}

char** parse_arg(int  argc,
		 char **argv,
		 int  *p_nb_arg)
{
   char       input_char;
   int        nb_arg;
   extern int opterr;
   char       *format = "qouhkrda";
   char       *larg = malloc(40);
   nb_arg = 0;
   opterr = 1;
   while ((input_char = getopt(argc, argv, format)) != -1)
   {
      if (input_char == 'q')
      {
	 printf("quit\n");
	 free(larg);
	 return (NULL);
      }
      parse_value(input_char, &larg, nb_arg);
      nb_arg++;
   }
   printf("larg = %s\n", larg);
   return (concat_svname(argc, argv, optind, larg, p_nb_arg));
}
