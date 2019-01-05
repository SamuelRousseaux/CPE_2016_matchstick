/*
** useful.c for useful.c in /home/samuel/CPE/CPE_2016_matchstick
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Fri Feb 17 13:31:16 2017 Samuel
** Last update Sun Feb 26 14:13:42 2017 Samuel
*/

#include <unistd.h>
#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_getnbr(char *str)
{
  int	nbr;
  int	i;
  int	neg;
  int	c;
  int	lel;

  i = 1;
  nbr = 0;
  neg = 1;
  c = 1;
  lel = 0;
  if (str[0] == '-')
    {
      neg = -neg;
      lel = -1;
    }
  while ((i - lel) <= my_strlen(str))
    {
      nbr += (str[my_strlen(str) - i] - 48) * c;
      i++;
      c *= 10;
    }
  nbr *= neg;
  return (nbr);
}

void	put_remove(int HU_AI, char *nm, char *nl)
{
  if (HU_AI == 0)
    my_putstr("Player removed ");
  else
    my_putstr("AI removed ");
  my_putstr(nm);
  my_putstr(" match(es) from line ");
  my_putstr(nl);
  my_putstr("\n");
}

void	my_putnbr(int nb)
{
  int	div;

  div = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  while ((nb / div) >= 10)
    div *= 10;
  while (div > 0)
    {
      my_putchar((nb / div) % 10 + '0');
      div /= 10;
    }
}
