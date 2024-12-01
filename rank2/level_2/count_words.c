/*
Assignment name  : count_words
Expected files   : count_words.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that takes a string and counts the number of words in it.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

Your function must be declared as follows:

int count_words(char *str);

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

int count_words(char *str)
{
    int i = 0;
    int words = 0;

    while (str[i] == ' ')
        i++;

    while (str[i])
    {
        if (str[i] != ' ')
        {
            words++;
            while (str[i] && str[i] != ' ')
                i++;
        }
        else
            i++;
    }
    return (words);
}
