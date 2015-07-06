/*
** spec_read.c for strace in /home/charla_n/projects/strace/strace
**
** Made by nicolas charlas
** Login   <charla_n@epitech.net>
**
** Started on  Mon May  6 15:25:23 2013 nicolas charlas
** Last update Fri May 17 17:04:31 2013 nicolas charlas
*/

#include <stdio.h>
#include <sys/ptrace.h>
#include "specs.h"
#include "strace.h"

void	spec_read_write(ulli param_reg[MAX_ARG], int pid)
{
  int	i;
  char	word;

  print_int(param_reg[0]);
  dprintf(2, ", ");
  i = 0;
  word = 1;
  while (i < DISPLAY_STRCHAR && (unsigned int)i < param_reg[3])
    {
      word = (char)ptrace(PTRACE_PEEKTEXT, pid, param_reg[1], NULL);
      if (word >= 32 && word <= 126)
	dprintf(2, "%c", word);
      else if (word >= 7 && word <= 13)
	dprintf(2, "\\%d", (int)word);
      else
	dprintf(2, "\\%o", word);
      param_reg[1]++;
      i++;
    }
  if ((unsigned int)i < param_reg[3])
    dprintf(2, "...");
  dprintf(2, "\", ");
  print_int(param_reg[2]);
  dprintf(2, ")");
}
