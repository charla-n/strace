/*
** do_father.c for do_father in /home/jansen_a/svn/strace
** 
** Made by arthur jansen
** Login   <jansen_a@epitech.net>
** 
** Started on  Fri May 10 10:23:58 2013 arthur jansen
** Last update Thu May 16 18:42:41 2013 arthur jansen
*/

#include <sys/ptrace.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include "strace.h"

static int			is_sig_catched(int status, int pid)
{
  int				sig;

  if (!WIFSIGNALED(status))
    return (FAIL);
  dprintf(2, "\r+++ %d killed by ", pid);
  sig = WTERMSIG(status);
  if (sig == 2)
    dprintf(2, "SIGINT +++\n");
  else if (sig == 3)
    dprintf(2, "SIGQUIT +++\n");
  else if (sig == 7)
    dprintf(2, "SIGBUS +++\n");
  else if (sig == 8)
    dprintf(2, "SIGFPE +++\n");
  else if (sig == 9)
    dprintf(2, "SIGKILL +++\n");
  else if (sig == 11)
    dprintf(2, "SIGSEGV +++\n");
  else if (sig == 13)
    dprintf(2, "SIGPIPE +++\n");
  else if (sig == 15)
    dprintf(2, "SIGTERM +++\n");
  else if (sig == 19)
    dprintf(2, "SIGSTOP +++\n");
  return (SUCCESS);
}

static int			print_traced_syscall(int pid, t_syscall *sys)
{
  int				status;
  struct user_regs_struct	regs;

  while (1)
    {
      if (waitpid(pid, &status, 0) == -1)
	{
	  dprintf(2, "ERROR waitpid %s\n", strerror(errno));
	  return (SUCCESS);
	}
      ptrace(PTRACE_GETREGS, pid, 0, &regs);
      if (!is_sig_catched(status, pid))
	return (WEXITSTATUS(status));
      if (!WIFSTOPPED(status))
	return (WEXITSTATUS(status));
      if (regs.orig_rax != (ulli)-1)
	display_syscall(pid, find_syscall(regs.orig_rax, sys), &regs);
      ptrace(PTRACE_SINGLESTEP, pid, 0, 0);
    }
  return (SUCCESS);
}

int				do_father(int pid, t_syscall *sys,
					  t_type type)
{
  g_signinfo.pid = pid;
  if (type == PID)
    {
      g_signinfo.type = PID;
      if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1)
	return (write_error("ptrace(do_father_pid) "));
      dprintf(2, "Trace pid [%d]\n", pid);
    }
  return (print_traced_syscall(pid, sys));
}
