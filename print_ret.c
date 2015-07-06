/*
** print_ret.c for print_ret in /home/charla_n/projects/strace/strace
**
** Made by nicolas charlas
** Login   <charla_n@epitech.net>
**
** Started on  Mon May  6 00:18:47 2013 nicolas charlas
** Last update Fri May 17 16:51:30 2013 nicolas charlas
*/

#include <stdio.h>
#include <sys/user.h>
#include "strace.h"

void	print_ret(struct user_regs_struct *regs)
{
  ((int)regs->rax >= TOO_BIG || (int)regs->rax < -124) ?
    dprintf(2, "\t= %#lx\n", regs->rax) :
    ((int)regs->rax >= -124 && (int)regs->rax <= -1) ?
    dprintf(2, "\t= -1\n") :
    dprintf(2, "\t= %d\n", (int)regs->rax);
}
