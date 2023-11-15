#include "main.h"
#include <stdarg.h>
#include <unistd.h>


int _putchar(char c)
{
    return(write(1, &c, 1));
}


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
