#ifndef CTL_PARSE_H_
# define CTL_PARSE_H_

typedef struct s_oau t_oau;
struct s_oau
{
   int a;
   int u;
   int o;
};
char **parse_arg(int  argc,
		 char **argv,
		 int  *p_nb_arg);

#endif /* !CTL_PARSE */
