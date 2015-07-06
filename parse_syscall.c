/*
** parse_syscall.c for parse_syscall in /home/charla_n/projects/strace/strace
** 
** Made by nicolas charlas
** Login   <charla_n@epitech.net>
** 
** Started on  Tue Apr 30 13:44:41 2013 nicolas charlas
** Last update Mon May  6 21:40:06 2013 nicolas charlas
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "strace.h"

static int	put_in_list(char *line, t_syscall **sys)
{
  t_syscall	*elem;
  char		*syscall_str;
  char		*syscall_id;

  if ((syscall_str = strtok(line, " ")) == NULL)
    return (LINE_PARSE_ERR);
  if ((syscall_id = strtok(NULL, "\0")) == NULL)
    return (LINE_PARSE_ERR);
  if ((elem = malloc(sizeof(t_syscall))) == NULL)
    return (FAIL);
  elem->id = atoi(syscall_id);
  elem->syscall = strdup(syscall_str);
  elem->next = *sys;
  *sys = elem;
  return (SUCCESS);
}

int	parse_syscall(t_syscall **sys)
{
  FILE		*fd;
  char		*line;
  size_t	size;
  int		i;
  int		ret;

  size = 256;
  line = NULL;
  i = 0;
  if ((fd = fopen(FILE_SYSCALL, "r")) == NULL)
    return (FAIL);
  while (getline(&line, &size, fd) != -1)
    {
      if ((ret = put_in_list(line, sys)) == FAIL)
	return (FAIL);
      if (ret == LINE_PARSE_ERR)
	printf("Error parsing line %d\n", i);
      i++;
    }
  fclose(fd);
  return (SUCCESS);
}
