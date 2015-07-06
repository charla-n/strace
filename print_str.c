/*
** print_str.c for print_str in /home/jansen_a/svn/strace
**
** Made by arthur jansen
** Login   <jansen_a@epitech.net>
**
** Started on  Mon May  6 17:22:09 2013 arthur jansen
** Last update Fri May 17 16:59:11 2013 nicolas charlas
*/

#include <sys/ptrace.h>
#include <stdio.h>
#include "strace.h"

void		print_str(int pid, ulli reg)
{
  char		word;
  int		nbr_dis;

  nbr_dis = 0;
  word = 1;
  dprintf(2, "\"");
  while ((word = (char)ptrace(PTRACE_PEEKTEXT, pid, reg, NULL)) != '\0'
	 && nbr_dis < DISPLAY_STRCHAR)
    {
      if (word >= 32 && word <= 126)
	dprintf(2, "%c", word);
      else if (word >= 7 && word <= 13)
	dprintf(2, "\\%d", (int)word);
      else if (word != 0)
	dprintf(2, "\\%o", word);
      reg++;
      nbr_dis++;
    }
  if (word != '\0')
    dprintf(2, "...");
  dprintf(2, "\"");
}
