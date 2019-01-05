/*
** create_map.c for create_map in /home/samuel/CPE/CPE_2016_matchstick
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Fri Feb 17 13:21:49 2017 Samuel
** Last update Wed Feb 22 15:23:35 2017 Samuel
*/

#include <stdlib.h>
#include "my.h"

t_create_map	fill_space(t_create_map s)
{
  s.nb = 0;
  while (s.nb != s.space)
    {
      s.map[s.i][s.col] = ' ';
      s.col++;
      s.nb++;
    }
  return (s);
}

t_create_map	if_between(t_create_map s)
{
  s.map[s.i][s.col] = '*';
  s.col++;
  s = fill_space(s);
  s.nb = 0;
  while (s.nb != s.stick)
    {
      s.map[s.i][s.col] = '|';
      s.col++;
      s.nb++;
    }
  s = fill_space(s);
  s.map[s.i][s.col] = '*';
  s.map[s.i][s.col + 1] = '\0';
  s.space++;
  s.stick -= 2;
  return (s);
}

t_create_map	if_first_or_last(int nb_line, t_create_map s)
{
  while (s.col < (nb_line * 2 + 1))
    {
      s.map[s.i][s.col] = '*';
      s.col++;
    }
  s.map[s.i][s.col] = '\0';
  return (s);
}

char		**create_map(int nb_line)
{
  t_create_map	s;

  s.stick = nb_line * 2 - 1;
  s.space = 0;
  s.i = nb_line + 1;
  if ((s.map = malloc(sizeof(char *) * (nb_line + 3))) == NULL)
    return (NULL);
  s.map[nb_line + 2] = NULL;
  while (s.i >= 0)
    {
      s.col = 0;
      s.map[s.i] = malloc(sizeof(char) * (nb_line * 2 + 2));
      if (s.i == nb_line + 1 || s.i == 0)
	s = if_first_or_last(nb_line, s);
      else
	s = if_between(s);
      s.i--;
    }
  return (s.map);
}
