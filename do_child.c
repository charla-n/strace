/*
** do_child.c for do_child in /home/jansen_a/svn/strace
** 
** Made by arthur jansen
** Login   <jansen_a@epitech.net>
** 
** Started on  Fri May 10 10:38:28 2013 arthur jansen
** Last update Fri May 10 10:41:31 2013 arthur jansen
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include "strace.h"

int	do_child(char **args)
{
  dprintf(2, "Trace prog [%s]\n", args[0]);
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    return (write_error("ptrace(do_child) "));
  if (execvp(args[0], args) == -1)
    return (write_error("do_child(execvp) "));
  return (SUCCESS);
}
