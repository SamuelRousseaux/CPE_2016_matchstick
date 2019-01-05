/*
** get_next_line.c for get_next_line in /home/samuel/CPE/CPE_2016_matchstick
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Sun Feb 19 15:49:12 2017 Samuel
** Last update Sun Feb 26 14:11:19 2017 Samuel
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char		*get_next_line(const int fd)
{
  static int	eof = 0;
  int		i;
  char		*line;
  char		*c;

  i = 0;
  if ((line = malloc(sizeof(char) * 1000)) == NULL
      || (c = malloc(sizeof(char) * 2)) == NULL)
    return (NULL);
  c[0] = 0;
  while (c[0] != '\n')
    {
      eof = (read(fd, c, 1) < 1) ? 1 : 0;
      if (eof == 1)
	return (NULL);
      line[i] = c[0];
      i++;
    }
  line[i - 1] = '\0';
  free(c);
  return (line);
}
