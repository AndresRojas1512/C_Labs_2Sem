#ifndef FUNCTIONS_01_H
#define FUNCTIONS_01_H

#include <stdio.h>
#include <stdlib.h>

char *my_strpbrk(char *str1, char *str2);
size_t my_strspn(char *str1, char *str2);
size_t my_strcspn(char *str1, char *str2);
char *my_strchr(char *str, int c);
char *my_strrchr(char *str, int c);

#endif