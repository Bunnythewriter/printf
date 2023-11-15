#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _print_int_num - function to print numbers
 * @number: The integer expected 
 * Return: The integer
*/
int _print_int_num(int number)
{
    int count = 0;
    if (number < 0)
    {
        count += _putchar('-');
        number = -number;
    }

    if (number / 10 != 0)
    {
        _print_int_num(number / 10);
    }
       count += _putchar('0' + number % 10);
    

    return (count);
}