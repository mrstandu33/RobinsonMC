/*
** gameloop.c for RobinsonMC in /home/mrstandu33/Downloads/RobinsonMC/navy
**
** Made by daniel_s
** Login   <mrstandu33@epitech.net>
**
** Started on  Thu Feb 16 19:41:18 2017 daniel_s
** Last update Thu Feb 16 20:09:16 2017 daniel_s
*/

static char     *my_strncpy(char *dest, char *src, int n)
{
  int           i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  if (n < i)
    dest[i] = '\0';
  return (dest);
}

static char     *add_to_line(char *line, int treat, char *buff, int *start)
{
  char          *newlen;
  int           oldlen;

  if (line != 0)
    oldlen = my_strlen(line);
  else
    oldlen = 0;
  newlen = malloc((oldlen + treat + 1) * sizeof(*newlen));
  if (line != 0)
    my_strncpy(newlen, line, oldlen);
  else
    my_strncpy(newlen, "", oldlen);
  newlen[oldlen + treat] = 0;
  my_strncpy(newlen + oldlen, buff + *start, treat);
  if (line)
    free(line);
  *start = *start + (treat + 1);
  return (newlen);
}

char            *get_next_line(const int fd)
{
  static char   buff[MEM_SIZE];
  static int    nbinbuff = 0;
  static int    start;
  int           treat;
  char          *line;

  line = 0;
  treat = 0;
  while (1 == 1)
    {
      if (nbinbuff <= start)
	{
	  start = 0;
	  if (!(nbinbuff = read(fd, buff, MEM_SIZE)))
	    return (line);
	  if (nbinbuff == -1)
	    return (NULL);
	  treat = 0;
	}
      if (buff[start + treat] == '\n')
	return (line = add_to_line(line, treat, buff, &start));
      if (start + treat == nbinbuff - 1)
	line = add_to_line(line, treat + 1, buff, &start);
      treat = treat + 1;
    }
}

int	starter(char **my_str, char **enemy)
{
  while (1)
    {
      my_putstr("attack: ")

    }
}
