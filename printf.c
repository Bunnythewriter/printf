#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
* _printf - our custom printf
* @format: values to be printed
* Return: Same output as regular printf 
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
char s = va_arg(args, int);
count += _putchar(s);
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
count += _print_string(str);
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
count += _print_int_num(num);
}
else if (*format == 'u')
{
unsigned int num = va_arg(args, unsigned int);
count += unsign_int(num);
}
else {
_putchar('%');
format++;
_putchar(*format);
}
}
else
{        
count += _putchar(*format);
}
format++;
}
va_end(args);
return(count);
}
