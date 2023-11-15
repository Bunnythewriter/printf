#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * unsign_int - function to print integers of unsigned type
 * @number: Unsigned expected integer
 * Return: Unsigned integer value 
*/
int unsign_int(unsigned int number)
{
int count = 0;
if (number <= 0)
{
    count += _putchar('-');
    number = -number;
}
if (number / 10 != 0)
{
    count += _print_int_num(number / 10);
}
    count += _putchar('0' + number % 10);
return (count);
}
