/*
** specs_access.c for spec_access in /home/charla_n/projects/strace/strace
**
** Made by nicolas charlas
** Login   <charla_n@epitech.net>
**
** Started on  Sun May  5 23:19:17 2013 nicolas charlas
** Last update Fri May 17 16:59:58 2013 nicolas charlas
*/

#include <stdio.h>
#include <unistd.h>
#include "strace.h"
#include "specs.h"

static	t_sflags	g_flags[] =
  {
    {"R_OK", R_OK},
    {"W_OK", W_OK},
    {"X_OK", X_OK},
    {"", -1}
  };

void	spec_access(ulli param_reg[MAX_ARG], int pid)
{
  int	i;
  char	put_pipe;

  i = 0;
  put_pipe = 0;
  print_str(pid, param_reg[0]);
  dprintf(2, ", ");
  while (g_flags[i].flags != -1)
    {
      if (((long)param_reg[1] & g_flags[i].flags) == g_flags[i].flags)
	{
	  if (put_pipe == 1)
	    {
	      dprintf(2, "|");
	      put_pipe = 0;
	    }
	  dprintf(2, "%s", g_flags[i].name);
	  put_pipe++;
	}
      i++;
    }
  dprintf(2, ")");
}
