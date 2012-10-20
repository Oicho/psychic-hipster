#include "svwatch.h"

void child(char *svname)
{
  //char *svroot = getenv("SVROOT");
  printf("On lance le programme %s\n", svname);
  //chdir(svroot);
  chdir(svname);
  system("./run");
  printf("On a lance %s\n", svname);
}

static void logvalue(int  p_id,
		     char *sv_name)
{
  char *pipe;
  FILE *fl;

  pipe = get_path(sv_name);
  fl = fopen(pipe, "a");
  fprintf(fl, "%s\n%d\n",
	  sv_name,
	  p_id);
  if (WIFEXITED(p_id))
    fprintf(fl, "1\n%d\n", WEXITSTATUS(p_id));
  if (WIFSIGNALED(p_id))
    fprintf(fl, "0\n1\n%d\n", WTERMSIG(p_id));
  fprintf(fl, "====\n");
  fclose(fl);
}

void father(char *svname, int loop)
{
  pid_t p_id;
  int killed = 0;

  p_id = fork();
  if (p_id < 0)
  {
    printf("Fork failed in svwatch.\n");
    exit (-1);
  }
  if (p_id > 0)
  {
    printf("Luke, I'm your father.\n");
    while (loop && !killed)
    {
      if (waitpid(p_id, NULL, WNOHANG) > 0)
      {
	killed = 1;
	logvalue(p_id, svname);
	father(svname, loop);
      }
    }
  }
  if (p_id == 0)
    child(svname);
}

/**
 * Set the svname
 */
char *set_svname(int  argc,
		 char **argv,
		 int  *loop)
{
  if (argc < 2)
    _exit(-1);
  if (argc > 2)
  {
    if (!strcmp(argv[1], "-o"))
    {
      *loop = 0;
      return (argv[2]);
    }
    else
    {
      printf("Wrong argument(s).\n");
      printf("Please type --help for additional informations.\n");
      _exit(-1);
    }
  }
  if (!strcmp(argv[1], "--help"))
    {
      print_help_svwatch();
      _exit(-1);
    }
  return (argv[1]);
}

static void init_act(char *svname)
{
  struct sigaction act_term;
  struct sigaction act_kill;
  struct sigaction act_hup;

  get_path(svname);
  act_term.sa_handler = &action_term;
  act_kill.sa_handler = &action_kill;
  act_hup.sa_handler = &action_hup;
  act_term.sa_flags = 0;
  act_kill.sa_flags = 0;
  act_hup.sa_flags = 0;

  if (sigaction(SIGTERM, &act_term, NULL) < 0 ||
      sigaction(SIGUSR1, &act_kill, NULL) < 0 ||
      sigaction(SIGHUP, &act_hup, NULL) < 0)
    perror ("sigaction");
}

int main (int  argc,
	  char **argv)
{
  int loop = 1;
  char *svname;

  svname = set_svname(argc, argv, &loop);
  init_act(svname);
  father(svname, loop);
}
