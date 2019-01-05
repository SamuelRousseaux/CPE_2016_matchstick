/*
** main.c for main in /home/samuel/CPE/CPE_2016_matchstick
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Fri Feb 17 13:19:16 2017 Samuel
** Last update Sun Feb 26 13:54:58 2017 Samuel
*/

#include <unistd.h>
#include "my.h"

void	print_help()
{
  my_putstr(HELP);
}

void	print_error(char *error)
{
  write(2, error, my_strlen(error));
  return ;
}

int	main(int ac, char **av)
{
  int	nb_line;
  int	nb_matches;
  char	**map;

  if (ac != 3 || (av[1][0] == '-' && av[1][1] == 'h'))
    {
      print_help();
      return (EXIT_HELP);
    }
  if (verify_if_numbers(av) == 1)
    return (EXIT_WRONG_PARAMETERS);
  nb_line = my_getnbr(av[1]);
  nb_matches = my_getnbr(av[2]);
  if (error_ini(nb_line, nb_matches) == 1)
    return (EXIT_WRONG_PARAMETERS);
  map = create_map(nb_line);
  return (game(map, nb_line, nb_matches));
}
