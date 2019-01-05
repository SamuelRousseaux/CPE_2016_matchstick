/*
** useful_2.c for useful_2 in /home/samuel/CPE/CPE_2016_matchstick/src
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Mon Feb 20 15:41:53 2017 Samuel
** Last update Wed Feb 22 15:24:31 2017 Samuel
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

char	*int_to_str(int nb)
{
  char	*str;

  if ((str = malloc(sizeof(char) * 4) + 1) == NULL)
    return (NULL);
  if (nb < 10)
    {
      str[0] = nb + 48;
      str[1] = '\0';
    }
  else if (nb < 100)
    {
      str[0] = nb / 10 + 48;
      str[1] = nb % 10 + 48;
      str[2] = '\0';
    }
  else
    {
      str[0] = nb / 100 + 48;
      str[1] = nb / 10 % 10 + 48;
      str[2] = nb % 10 + 48;
      str[3] = '\0';
    }
  return (str);
}
