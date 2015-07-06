/*
** specs_mprotect.c for specs_mprotect in /home/charla_n/projects/strace/strace
**
** Made by nicolas charlas
** Login   <charla_n@epitech.net>
**
** Started on  Sun May  5 23:18:56 2013 nicolas charlas
** Last update Fri May 17 17:02:49 2013 nicolas charlas
*/

#include <stdio.h>
#include <sys/mman.h>
#include "strace.h"
#include "specs.h"

static t_sflags	g_flags_prot[] =
  {
    {"PROT_READ", PROT_READ},
    {"PROT_WRITE", PROT_WRITE},
    {"PROT_EXEC", PROT_EXEC},
    {"", -1}
  };

static void	print_mprotect_prot(ulli param_reg[MAX_ARG])
{
  int		i;
  char		put_pipe;

  i = 0;
  put_pipe = 0;
  while (g_flags_prot[i].flags != -1)
    {
      if (((long)param_reg[2] & g_flags_prot[i].flags) ==
	  g_flags_prot[i].flags)
	{
	  if (put_pipe == 1)
	    {
	      dprintf(2, "|");
	      put_pipe = 0;
	    }
	  dprintf(2, "%s", g_flags_prot[i].name);
	  put_pipe++;
	}
      i++;
    }
  if (!put_pipe)
    dprintf(2, "PROT_NONE");
}

void		spec_mprotect(ulli param_reg[MAX_ARG],
			      __attribute__((unused))int pid)
{
  print_ptr(param_reg[0]);
  dprintf(2, ", ");
  print_int(param_reg[1]);
  dprintf(2, ", ");
  print_mprotect_prot(param_reg);
  dprintf(2, ")");
}
