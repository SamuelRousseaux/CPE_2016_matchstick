/*
** game.c for game in /home/samuel/CPE/CPE_2016_matchstick/src
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Sun Feb 19 15:52:40 2017 Samuel
** Last update Sun Feb 26 14:05:23 2017 Samuel
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	**remove_match(char **map, int line, int matches)
{
  int	i;

  i = my_strlen(map[line]);
  while (matches > 0)
    {
      if (map[line][i] == '|')
	{
	  map[line][i] = ' ';
	  matches--;
	}
      i--;
    }
  return (map);
}

char	**human(char **map, int nl, int nm)
{
  char	*line;
  char	*matches;
  int	a;

  a = 0;
  my_putstr("\nYour turn:\n");
  while (a == 0)
    {
      while (a == 0)
	{
	  my_putstr("Line: ");
	  if ((line = get_next_line(0)) == NULL)
	    return (NULL);
	  a = (verify_line(line, nl) == 1) ? 1 : 0;
	}
      a = 0;
      my_putstr("Matches: ");
      if ((matches = get_next_line(0)) == NULL)
	return (NULL);
      a = (verify_matches(matches, nm, map, my_getnbr(line)) == 1) ? 1 : 0;
    }
  put_remove(0, matches, line);
  map = remove_match(map, my_getnbr(line), my_getnbr(matches));
  return (map);
}


char	**ai(char **map, int nl, int nm)
{
  int	line;
  int	matches;

  my_putstr("\nAI's turn...\n");
  line = choose_line(map, nl);
  matches = choose_matches(map, line, nm);
  put_remove(1, int_to_str(matches), int_to_str(line));
  map = remove_match(map, line, matches);
  return (map);
}

int	game(char **map, int nl, int nm)
{
  srand(getpid());
  while (1)
    {
      print_map(map);
      if ((map = human(map, nl, nm)) == NULL)
	return (0);
      print_map(map);
      if (if_end(map) == 1)
	{
	  my_putstr("You lost, too bad...\n");
	  return (2);
	}
      if ((map = ai(map, nl, nm)) == NULL)
	return (0);
      if (if_end(map) == 1)
	{
	  print_map(map);
	  my_putstr("I lost... snif... but I'll get you next time!!\n");
	  return (1);
	}
    }
  free_map(map);
  return (0);
}
