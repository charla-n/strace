/*
** print_ptr.c for print_ptr in /home/jansen_a/svn/strace
** 
** Made by arthur jansen
** Login   <jansen_a@epitech.net>
** 
** Started on  Mon May  6 17:22:52 2013 arthur jansen
** Last update Mon May  6 17:23:12 2013 arthur jansen
*/

#include <stdio.h>
#include "strace.h"

void	print_ptr(ulli reg)
{
  (reg == 0) ? dprintf(2, "NULL") :
    dprintf(2, "%#lx", (long unsigned int)reg);
}
