#include <string.h>

/* We need to free the char* return by this func */

char *separate_svname(char *input,
		      int  pos)
{
   int length, i, outp_len;
   char *output;
   outp_len = length - pos - 1;
   length = strlen(input);
   output = malloc(sizeof(char) * output_len);
   for (i = 0; i < output_len; i++)
   {
      output[i] = input[pos + i];
   }
   return (output);
}
void all_parse(char operand[2],
	       char *svname,
	       s_struct snamelist)
{
   switch (operand[1])
   {
      case 'd':

	 break;
      case 'r':

	 break;
      case 'k':

	 break;
      case 'h':

	 break;
   }
}
void call_function(char operand[2],
		   char *svname,
		   s_struct snamelist)
{
   switch (operand[0])
   {
      case 'a':
	 all_parse(operand, svname, snamelist)
	 break;
      case 'o':

	 break;
      case 'd':

	 break;
      case 'k':

	 break;
      case 'h'

	 break;
      case 'r':

	 break;
      case 'u':

	 break;
   }
   free(svname);
}
void parse_monitor(char *input,
		  s_struct s_namelist)
{
   int  i, b, nb_operand;
   char operand[2] = "";
   char *svname;

   for (i = 0, b = 1, operand = 0; (input[i] != '\0') && b; i++)
   {
      if (input[i] == '-')
      {
	 i++;
	 if (input == 'z')
	 {
	    /* appele au ici */
	    return ;
	 }
	 if (input == 'y')
	 {
	    /* appele au once ici */
	    return ;
	 }
	 operand[nb_operand] = input[i];
	 nb_operand++;
      }
      else if (input[i] != ' ')
	 b = 0;
   }
   call_function(operand, separate_svname(input, i), s_namelist);
}
