/*
** print_int.c for print_int in /home/jansen_a/svn/strace
** 
** Made by arthur jansen
** Login   <jansen_a@epitech.net>
** 
** Started on  Mon May  6 17:21:26 2013 arthur jansen
** Last update Wed May  8 17:06:53 2013 nicolas charlas
*/

#include <stdio.h>
#include "strace.h"

void	print_int(int reg)
{
  (reg > TOO_BIG) ? dprintf(2, "%#lx", (long)reg) :
    dprintf(2, "%ld", (long)reg);
}
