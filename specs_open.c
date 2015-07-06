/*
** specs.c for specs in /home/charla_n/projects/strace/strace
** 
** Made by nicolas charlas
** Login   <charla_n@epitech.net>
** 
** Started on  Sun May  5 21:55:26 2013 nicolas charlas
** Last update Wed May  8 16:47:53 2013 nicolas charlas
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "strace.h"
#include "specs.h"

static t_sflags	g_flags[] =
  {
    {"O_RDONLY", O_RDONLY},
    {"O_WRONLY", O_WRONLY},
    {"O_RDWR", O_RDWR},
    {"O_CREAT", O_CREAT},
    {"O_DIRECTORY", O_DIRECTORY},
    {"O_EXCL", O_EXCL},
    {"O_NOCTTY", O_NOCTTY},
    {"O_NOFOLLOW", O_NOFOLLOW},
    {"O_TRUNC", O_TRUNC},
    {"O_CLOEXEC", O_CLOEXEC},
    {"O_APPEND", O_APPEND},
    {"O_ASYNC", O_ASYNC},
    {"O_NONBLOCK", O_NONBLOCK},
    {"O_SYNC", O_SYNC},
    {"", -1}
  };

void	spec_open(ulli param_reg[MAX_ARG], int pid)
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
