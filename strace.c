/*
** strace.c for strace in /home/charla_n/projects/strace
** 
** Made by nicolas charlas
** Login   <charla_n@epitech.net>
** 
** Started on  Mon Apr 29 15:52:40 2013 nicolas charlas
** Last update Thu May 16 18:47:36 2013 arthur jansen
*/

#include <sys/ptrace.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/reg.h>
#include <sys/user.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include "strace.h"

static void	free_args(char **args)
{
  int		i;

  i = 0;
  while (args && args[i])
    free(args[i++]);
  free(args);
}

int		strace(char **av)
{
  int		type;
  int		pid;
  char		**args;
  t_syscall	*sys;

  args = NULL;
  sys = NULL;
  if ((type = parse_args(av, &args)) == FAIL)
    return (FAIL);
  if (parse_syscall(&sys) == FAIL)
    return (FAIL);
  if (type == SUCCESS)
    {
      if ((pid = fork()) == -1)
	return (write_error("strace(fork) "));
      if (!pid)
	do_child(args);
      else
	dprintf(2, "+++ exited with %d +++\n", do_father(pid, sys, PROG));
    }
  else
    dprintf(2, "+++ exited with %d +++\n", do_father(atoi(av[2]), sys, PID));
  free_args(args);
  return (SUCCESS);
}
