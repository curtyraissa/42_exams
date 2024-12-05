#include "utils.h"

int is_space(char c)
{
    return (c == ' ' || (c >= '\t' && c <= '\r'));
}
int is_letter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
int is_lower(char c)
{
    return (c >= 'a' && c <= 'z');
}
int is_upper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}
int ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return(len);
}
void ft_putchar(int c)
{
    write(1, &c, 1);
}
void ft_putstr(const char *str)
{
    int i = 0;

    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}
void ft_putnbr(int n)
{
    char c;

    if (n > 9)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}
int ft_atoi(const char *str)
{
    int i = 0;
    int result = 0;

    while (is_digit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);
}

void ft_puthex(int n)
{
    char c;
    char *hex = "0123456789abcdef";

    if (n >= 16)
        ft_puthex(n / 16);
    c = hex[n % 16];
    write(1, &c, 1);
}

