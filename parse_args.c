/*
** parse_args.c for parse_args in /home/charla_n/projects/strace/strace
** 
** Made by nicolas charlas
** Login   <charla_n@epitech.net>
** 
** Started on  Tue Apr 30 12:41:21 2013 nicolas charlas
** Last update Wed May  8 17:30:36 2013 nicolas charlas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strace.h"

static int	count_args(char **av)
{
  int		count;

  count = 1;
  while (av[count])
    count++;
  return (count);
}

static int	parse_pid(char *pid)
{
  return (pid ? atoi(pid) : FAIL);
}

int	parse_args(char **av, char ***args)
{
  int	count;
  int	i;
  int	ret;

  if (!strcmp(av[1], "-p"))
    {
      if ((ret = parse_pid(av[2])) < 1)
	dprintf(2, "Pid entered not valid\n");
      return (ret < 1 ? FAIL : ret);
    }
  count = count_args(av);
  if ((*args = malloc(sizeof(char *) * (count + 1))) == NULL)
    return (FAIL);
  i = 1;
  count = 0;
  while (av[i])
    {
      (*args)[count++] = strdup(av[i]);
      i++;
    }
  (*args)[count] = NULL;
  return (SUCCESS);
}
