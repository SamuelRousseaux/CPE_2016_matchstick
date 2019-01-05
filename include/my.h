/*
** my.h for my in /home/samuel/scripts
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Thu Dec 15 13:53:46 2016 Samuel
** Last update Sun Feb 26 14:22:47 2017 Samuel
*/

#ifndef MY_H_
# define MY_H_
# define EXIT_HELP 0
# define EXIT_WRONG_PARAMETERS 84
# define HELP "\n  "\
  "Usage: ./matchstick [number of line] [matches per turn]\n"\
  "    The number of line must be between 1 & 100.\n"\
  "    The number of matches per turn must be superior to 0.\n"\
  "\n  Play against the AI in this reproduction of the"\
  " famous game: matchstick.\n\n"
# define ERROR_NUMBER "\nError: Please enter only numbers\n\n"
# define ERROR_LINE "\nError: Please enter a number of line between 1 & 100\n\n"
# define ERROR_MATCH "\nError: You must be able to remove at least 1 match\n\n"
# define ERROR_INPUT "Error: invalid input (positive number expected)\n"
# define ERROR_REM_MATCH "Error: you have to remove at least one match\n"
# define ERROR_NB_MATCH "Error: not enough matches on this line\n"
# define ERROR_OUT_OF_RANGE "Error: this line is out of range\n"

typedef struct	s_create_map
{
  char		**map;
  int		i;
  int		col;
  int		space;
  int		stick;
  int		nb;
}		t_create_map;

int	choose_line(char **, int);
int	choose_matches(char **, int, int);
char	**create_map(int);
int	error_ini(int, int);
void	free_map(char **);
int	game(char **, int, int);
char	*get_next_line(const int);
int	if_end(char **);
char	*int_to_str(int);
int	my_getnbr(char *);
void	my_putchar(char);
void	my_putnbr(int);
void	my_putstr(char *);
int	my_strlen(char *);
int	number_of_matches(char **, int);
void	print_error(char *);
void	print_map(char **);
void	put_remove(int, char *, char *);
int	verify_if_number(char *);
int	verify_if_numbers(char **);
int	verify_line(char *, int);
int	verify_matches(char *, int, char **, int);

#endif /* !MY_H_ */
