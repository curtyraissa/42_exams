#ifndef UTILS_H
# define UTILS_H

# include <unistd.h> //write
# include <stdio.h> //printf
# include <stdlib.h> //malloc
# include <stddef.h> //size_t
# include <string.h> //NULL

int is_space(char c);
int is_letter(char c);
int is_lower(char c);
int is_upper(char c);
int is_digit(char c);
int ft_strlen(const char *str);
void ft_putchar(int c);
void ft_putstr(const char *str);
void ft_putnbr(int n);
int ft_atoi(const char *str);
void ft_puthex(int n);

#endif