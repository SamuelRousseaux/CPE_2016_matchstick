/*
** verify_input.c for verify_input in /home/samuel/CPE/CPE_2016_matchstick/src
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Mon Feb 20 15:24:47 2017 Samuel
** Last update Sun Feb 26 14:18:53 2017 Samuel
*/

#include "my.h"

int	verify_if_number(char *nb)
{
  int	i;

  i = 0;
  while (nb[i] != '\0')
    {
      if (nb[i] >= '0' && nb[i] <= '9')
	i++;
      else
	return (1);
    }
  return (0);
}

int	verify_line(char *cline, int nb_line)
{
  int	line;

  if (verify_if_number(cline) == 1)
    {
      my_putstr(ERROR_INPUT);
      return (0);
    }
  line = my_getnbr(cline);
  if (line < 1 || line > nb_line)
    {
      my_putstr(ERROR_OUT_OF_RANGE);
      return (0);
    }
  return (1);
}

int	verify_matches(char *cmatch, int nb_match, char **map, int line)
{
  int	match;

  if (verify_if_number(cmatch) == 1)
    my_putstr(ERROR_INPUT);
  if (verify_if_number(cmatch) == 1)
    return (0);
  match = my_getnbr(cmatch);
  if (match < 1)
    {
      my_putstr(ERROR_REM_MATCH);
      return (0);
    }
  if (match > nb_match)
    {
      my_putstr("Error: you cannot remove more than ");
      my_putnbr(nb_match);
      my_putstr(" matches per turn\n");
      return (0);
    }
  if (number_of_matches(map, line) < match)
    {
      my_putstr(ERROR_NB_MATCH);
      return (0);
    }
  return (1);
}
