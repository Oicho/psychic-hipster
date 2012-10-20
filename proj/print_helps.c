#include "print_helps.h"

void print_help_svwatch(void)
{
  printf("NAME\n\tsvwatch - is a watchdog\n\nSYNOPSIS\t");
  printf("svmatch [-o] svname\nDESCRIPTION\n\t-o, once\n");
  printf("\tThe service is not relaunch if it fails.\n");
  printf("\tsvname is the name of the directory where svmatch go to find");
  printf("the \"run\" executable file\n");
}
void print_help_svmonitor(void)
{

}
void print_help_svctl(void)
{
    printf("NAME\n\tsvctl - is a services controler\n\nSYNOPSIS\t");
    printf("svctl [-o] [-a] [-udrkh]svname [svname2..]\n");
    printf("DESCRIPTION\n\t-o, once\n");
    printf("\tThe service is not relaunch if it fails. This commmand");
    printf("make sense only if used with -u.\n")
    printf("\t-a, all\n");
    printf("\tThis commands following -a will be applied to all the services");
    printf(".\n\t-u, up\n");
    printf("svctl will start the service required\n");
    printf("\t-d, down\n\tStop the service by sending the SIGTERM signal\n");
    printf("\t-r, restart\n\t");
    printf("Restart the service required.\n\t-k, kill\n");
    printf("Kill the service by sending the SIGKILL signal\n\t-h, hup\n\t");
    printf("Send the signal SIGHUP to the service.");
    printf("\tsvname is the name of the service svctl is going to ");
    printf("modify|create.\n");
}
