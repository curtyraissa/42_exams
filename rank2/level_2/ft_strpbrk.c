/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
*/

// strpbrk: Encontra o primeiro caractere correspondente.

#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i;

    while (*s1)
    {
        i = 0;
        while(s2[i])
        {
            if (s2[i] == *s1)
                return ((char *)s1);
            i++;
        }
        s1++;
    }
    return (NULL);
}