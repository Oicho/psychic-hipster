# include "svwatch.h"

static char *my_strcat(char *dest,
		       char *str)
{
    size_t dest_len = strlen(dest);
    size_t str_len = strlen(str);

    
    str_len += dest_len;
    dest = strdup(dest);
    str = strdup(str);
    dest = strcat(dest, str);
    free(str);
    return (dest);
}

char *get_path(char *svname)
{
  char *var;

  var = getenv("LOGPIPE");
  if (var)
    return (var);
  else
    {
      var = getenv("SVROOT");
      if (!var)
	var = ".";
      var = my_strcat(var, "/");
      var = my_strcat(var, svname);
      var = my_strcat(var, "/log");
      setenv("LOGPIPE", var, 1);
      free(var);
      return (NULL);
    }
}

int get_chldpid(int i)
{
  static int chldpid;

  if (i)
    chldpid = i;
  return (chldpid);
}

void action_term(int sig)
{
  if (sig == SIGTERM)
    kill(get_chldpid(0), SIGTERM);
  printf("Terminated\n");
  exit(EXIT_SUCCESS);
}

void action_kill(int sig)
{
  if (sig == SIGUSR1)
    {
      kill(get_chldpid(0), SIGKILL);
      _exit(EXIT_SUCCESS);
    }
  else
    printf("erreur expected SIGUSR1");
}

void action_hup(int sig)
{
  if (sig == SIGHUP)
    kill(get_chldpid(0), SIGHUP);
  printf("Hangup\n");
  _exit(EXIT_SUCCESS);
}
