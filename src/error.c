/*
** error.c for error in /home/samuel/CPE/CPE_2016_matchstick/src
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Sat Feb 18 14:48:32 2017 Samuel
** Last update Sun Feb 26 14:01:26 2017 Samuel
*/

#include <stdlib.h>
#include "my.h"

int	verify_if_numbers(char **av)
{
  int	i;
  int	j;

  i = 1;
  while (av[i] != NULL)
    {
      j = 0;
      while (av[i][j] != '\0')
	{
	  if ((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '-')
	    j++;
	  else
	    {
	      print_error(ERROR_NUMBER);
	      return (1);
	    }
	}
      i++;
    }
  return (0);
}

int	error_ini(int nb_line, int nb_matches)
{
  if (nb_line < 1 || nb_line > 100)
    {
      print_error(ERROR_LINE);
      return (1);
    }
  if (nb_matches <= 0)
    {
      print_error(ERROR_MATCH);
      return (1);
    }
  return (0);
}
