/*
** verify.c for verify in /home/samuel/CPE/CPE_2016_matchstick/src
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Mon Feb 20 15:30:07 2017 Samuel
** Last update Sun Feb 26 14:14:36 2017 Samuel
*/

#include <stdlib.h>
#include "my.h"

int	number_of_matches(char **map, int line)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (map[line][i] != '\0')
    {
      if (map[line][i] == '|')
	nb++;
      i++;
    }
  return (nb);
}

int	if_end(char **map)
{
  int	i;
  int	i2;

  i = 0;
  while (map[i] != NULL)
    {
      i2 = 0;
      while (map[i][i2] != '\0')
	{
	  if (map[i][i2] == '|')
	    return (0);
	  i2++;
	}
      i++;
    }
  return (1);
}
