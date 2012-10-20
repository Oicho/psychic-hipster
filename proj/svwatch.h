#ifndef SVWATCH_H_
# define SVWATCH_H_
# define _BSD_SOURCE
# define _POSIX_SOURCE
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "print_helps.h"
# include <sys/stat.h>
# include <fcntl.h>

int get_chldpid(int i);

char *get_path(char *svname);

void action_term(int sig);

void action_kill(int sig);

void action_hup(int sig);

#endif /* SVWATCH_H_ */
