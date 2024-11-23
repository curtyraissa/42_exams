/*
Assignment name  : count_words
Expected files   : count_words.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a program that takes a string and counts the number of words in it.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply return 0.

Examples:

$> ./count_words "Hello world!" | cat -e
2$
$> ./count_words "   This is   a test string   " | cat -e
5$
$> ./count_words "123  abc, 456;" | cat -e
3$
$> ./count_words "  " | cat -e
0$
$>
*/

#include <unistd.h>

int count_words(char *str)
{
    int count = 0;
    int in_word = 0;  // Flag para saber se estamos dentro de uma palavra

    while (*str)
    {
        // Se o caractere for alfanumérico e não estamos dentro de uma palavra
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z') || (*str >= '0' && *str <= '9'))
        {
            if (!in_word)  // Se não estivermos já dentro de uma palavra
            {
                count++;  // Contamos a palavra
                in_word = 1;  // Marcamos que estamos dentro de uma palavra
            }
        }
        else
        {
            in_word = 0;  // Se for um caractere não alfanumérico (delimitador), saímos da palavra
        }
        str++;  // Avançamos para o próximo caractere
    }

    return count;
}
