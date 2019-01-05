/*
** useful_map.c for useful_map in /home/samuel/CPE/CPE_2016_matchstick/src
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Sat Feb 18 14:44:40 2017 Samuel
** Last update Sun Feb 26 14:14:11 2017 Samuel
*/

#include <stdlib.h>
#include "my.h"

void	print_map(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      my_putstr(map[i]);
      my_putstr("\n");
      i++;
    }
}

void	free_map(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      free(map[i]);
      i++;
    }
  free(map);
}
