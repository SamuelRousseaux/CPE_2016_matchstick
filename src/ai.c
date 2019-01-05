/*
** ai.c for ai in /home/samuel/CPE/CPE_2016_matchstick/src
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Mon Feb 20 18:01:37 2017 Samuel
** Last update Sun Feb 26 13:52:10 2017 Samuel
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	choose_matches(char **map, int line, int nb_matches)
{
  int	matches;
  int	nb_match;
  int	valid;

  valid = 0;
  nb_match = number_of_matches(map, line);
  while (valid == 0)
    {
      if (nb_match > 1)
	if (nb_match - 1 <= nb_matches)
	  return (nb_match - 1);
      matches = rand() % ((nb_match - 1) + 2);
      nb_match = nb_match;
      if (matches <= nb_match && matches <= nb_matches && matches > 0)
	valid = 1;
    }
  return (matches);
}

int		choose_line(char **map, int nb_line)
{
  int		line;
  int		valid;

  valid = 0;
  while (valid == 0)
    {
      line = rand() % ((nb_line - 1) + 2);
      if (number_of_matches(map, line) > 0)
	valid = 1;
    }
  return (line);
}
