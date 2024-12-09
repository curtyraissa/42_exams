/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdlib.h>

int ft_isspace(char c)
{
    return (c == ' ' || (c == '\t' && c == '\r'));
}

void ft_strncpy(char *dest, char *src, int n)
{
    int i = 0;
    while (i < n && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int count_words(char *str)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (!is_space(*str) && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (is_space(*str))
        {
            in_word = 0;
        }
        str++;
    }
    return (count);
}

char **ft_split(char *str)
{
    char **strtab;
    int word_count;
    int word_len;
    int i = 0;
    int start;

    word_count = count_words(str);
    strtab = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!strtab)
        return (NULL);

    while (*str)
    {
        while (*str && is_space(*str))
            str++;
        start = 0;
        while (str[start] && !is_space(str[start]))
            start++;
        if (start > 0)
        {
            word_len = start;
            strtab[i] = (char *)malloc(sizeof(char) * (word_len + 1));
            if (!strtab[i])
                return (NULL);
            ft_strncpy(strtab[i], str, word_len);
            i++;
            str += word_len;
        }
    }
    strtab[i] = NULL;
    return (strtab);
}