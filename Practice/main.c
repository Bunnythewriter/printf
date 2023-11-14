#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
   int len;
    int len2;
    int x = 10;
    int y = 20;
    len = _printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", x, y);
    _printf("Negative:[%d]\n", -762534);
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    _printf("Len:[%d]\n", x);
    _printf("Value of x is %d and value of y is %d\n", x, y);
    
    return (0);
}