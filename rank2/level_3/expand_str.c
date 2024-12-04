/*
Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/

#include <unistd.h>

int ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	main(int ac, char **av)
{
	int		end;

	if (ac == 2)
	{
		end = 0;
		while (*av[1] && ft_isspace(*av[1]))
			av[1]++;
		while (*av[1])
		{
			while (*av[1] && !ft_isspace(*av[1]))
				write(1, av[1]++, 1);
			while (*av[1] && ft_isspace(*av[1]))
			{
				av[1]++;
				if (*av[1] == '\0')
					end = 1;
			}
			if (!end)
				write(1, "   ", 3);
		}
	}
	write(1, "\n", 1);
	return (0);
}
