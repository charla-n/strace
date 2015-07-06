/*
** main.c for main in /home/charla_n/projects/strace
** 
** Made by nicolas charlas
** Login   <charla_n@epitech.net>
** 
** Started on  Mon Apr 29 15:47:02 2013 nicolas charlas
** Last update Fri May 17 16:42:21 2013 arthur jansen
*/

#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <stdlib.h>
#include "strace.h"

t_signinfo		g_signinfo;

void			detach_handler(__attribute__((unused))int sig)
{
  int			status;

  if (g_signinfo.type != PROG)
    {
      kill(g_signinfo.pid, SIGCONT);
      waitpid(g_signinfo.pid, &status, 0);
      ptrace(PTRACE_CONT, g_signinfo.pid, NULL, NULL);
      ptrace(PTRACE_DETACH, g_signinfo.pid, NULL, NULL);
      dprintf(2, "\r+++ Process %d detached +++\n", g_signinfo.pid);
    }
  exit(0);
}

static int		usage()
{
  dprintf(2, "Not enough parameters\n"
	  "Usage : ./strace [-p pid] | progname\n");
  return (FAIL);
}

int			main(int ac, char **av)
{
  if (ac < 2)
    return (usage());
  g_signinfo.pid = 0;
  g_signinfo.type = PROG;
  signal(SIGINT, &detach_handler);
  signal(SIGCHLD, SIG_DFL);
  return (strace(av));
}
