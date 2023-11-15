#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * -print_string - function to print a string
 * @str: pointer to the expected string
 * Return: pointer to the expected string
*/
int _print_string(char *str)
{
    int count = 0;
    while(*str != '\0')
    {
        count += _putchar(*str);
        str++;
        count++;
    }

    return (count);
}