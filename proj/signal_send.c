# include "svmonitor.h"

void which_sig(int pid,
	       char *opt)
{
  if (opt == "-h")
    kill(pid, SIGHUP);
  else if (opt == "-k")
    kill(pid, SIGUSR1);
  else if (opt == "-d")
    kill(pid, SIGTERM);
}

void send_to_all(char     *opt,
		 s_svname *list)
{
  while (!list)
    {
      which_sig(list->pid, opt);
      list = list->next;
    }
}

/*
** sert aussi a verifier si il est present dans la list
** return 0 s'il ne trouve pas et le pid
*/
int find_pid(char *sv_name,
	     s_svname *list)
{
  while (!list && (list->svname !=  sv_name))
    {
      list = list->next;
    }
  if (!list)
    return (0);
  else
    return (list->pid);
}

int is_present(char *svname)
{
  while (!list && (list->svname !=  sv_name))
    {
      list = list->next;
    }
  if (!list)
    return (0);
  else
    return (1);
}

int send_sig(char     *svname,
	     char     *opt,
	     int      all,
	     s_svname *list)
{
  int pid;

  if (all)
    send_to_all(opt, list);
  else
    {
      pid = find_pid(svname, list);
      if (pid)
	which_sig(pid, opt);
    }
}
