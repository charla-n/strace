/*
** find_syscall.c for find_syscall in /home/charla_n/projects/strace/strace
** 
** Made by nicolas charlas
** Login   <charla_n@epitech.net>
** 
** Started on  Tue Apr 30 14:06:37 2013 nicolas charlas
** Last update Tue Apr 30 14:08:20 2013 nicolas charlas
*/

#include <stdlib.h>
#include "strace.h"

char		*find_syscall(int id, t_syscall *sys)
{
  t_syscall	*tmp;

  tmp = sys;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  return (tmp ? tmp->syscall : NULL);
}
