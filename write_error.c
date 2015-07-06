/*
** write_error.c for write_error in /home/charla_n/projects/strace
** 
** Made by nicolas charlas
** Login   <charla_n@epitech.net>
** 
** Started on  Mon Apr 29 16:00:08 2013 nicolas charlas
** Last update Mon Apr 29 16:00:46 2013 nicolas charlas
*/

#include <stdio.h>
#include <errno.h>
#include "strace.h"

int	write_error(char *error)
{
  perror(error);
  return (FAIL);
}
