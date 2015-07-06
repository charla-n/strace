/*
** display_param_type.c for strace in /home/jansen_a/svn/strace
**
** Made by arthur jansen
** Login   <jansen_a@epitech.net>
**
** Started on  Thu May  2 18:42:32 2013 arthur jansen
** Last update Fri May 17 17:09:35 2013 nicolas charlas
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include "strace.h"
#include "syscalls_generated.h"

static void	display_arg_type(int pid, int my_syscalls_num,
				 ulli param_reg[MAX_ARG])
{
  int		arg_num;

  arg_num = 0;
  if (strcmp(syscalls[my_syscalls_num].name, "restart_syscall") == 0)
    dprintf(2, "<... resuming interrupted call ...>)");
  else if (syscalls[my_syscalls_num].nb_args == 0)
    dprintf(2, ")");
  else
    {
      while (arg_num < syscalls[my_syscalls_num].nb_args)
	{
	  if (syscalls[my_syscalls_num].args[arg_num] == INT)
	    print_int(param_reg[arg_num]);
	  else if (syscalls[my_syscalls_num].args[arg_num] == STR)
	    print_str(pid, param_reg[arg_num]);
	  else if (syscalls[my_syscalls_num].args[arg_num] == PTR)
	    print_ptr(param_reg[arg_num]);
	  if (arg_num + 1 < syscalls[my_syscalls_num].nb_args)
	    dprintf(2, ", ");
	  else
	    dprintf(2, ")");
	  arg_num++;
	}
    }
}

static void	init_param_reg(ulli *param_reg, struct user_regs_struct *regs)
{
  param_reg[0] = regs->rdi;
  param_reg[1] = regs->rsi;
  param_reg[2] = regs->rdx;
  param_reg[3] = regs->r10;
  param_reg[4] = regs->r8;
  param_reg[5] = regs->r9;
}

void		display_syscall(int pid, char *name,
				struct user_regs_struct *regs)
{
  int		my_syscalls_num;
  ulli		param_reg[MAX_ARG];

  if (!name)
    return ;
  dprintf(2, "%s(", name);
  init_param_reg(&param_reg[0], regs);
  my_syscalls_num = 0;
  while (syscalls[my_syscalls_num].name &&
	 strcmp(syscalls[my_syscalls_num].name, name) != 0)
    my_syscalls_num++;
  if (syscalls[my_syscalls_num].specs)
    {
      if (!strcmp(syscalls[my_syscalls_num].name, "read") ||
	  !strcmp(syscalls[my_syscalls_num].name, "write"))
	param_reg[3] = regs->rax;
      syscalls[my_syscalls_num].specs(param_reg, pid);
    }
  else if (syscalls[my_syscalls_num].name)
    display_arg_type(pid, my_syscalls_num, param_reg);
  print_ret(regs);
}
