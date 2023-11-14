#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _print_char(char c)
{
    while (c != '\0') {
        _putchar(c);}
    return c; /*change 0*/
}

void _print_string(const char *format) {
    while (*format != '\0') {
        _putchar(*format);
        format++;
    }
}

int _print_num(int c)
{
    if (c < 0)
    {
        _putchar('-');
        c = -c;
    }

    if (c/10 != 0)
    {
        _print_num(c / 10);
    }
        _putchar('0' + c % 10);
        return c; /*CHANGE 1*/
    
}

void _print_dec(double n)
{
    int i;
    if (n < 0){
    _putchar('-');
    n = -n;}

    _print_num((int)n);

    _putchar('.');

    n -= (int)n;
    
    for (i = 0; i < 3; i++)
    {
    n *= 10;
    _putchar('0' + (int)n);
    n -= (int)n;
    }
}

int _printf(const char *format, ...)
{
    va_list argc;
    va_start(argc, *format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
            case 'c': /*handle character*/
                {
                    char sc = va_arg(argc, int);
                    _putchar(sc);
                }
                break;
                
            case 's': /*handle string*/
                {
                    char *format = va_arg(argc, char *);
                    _print_string(format);
                }
                break;

            case 'd': /*Handle integer*/
            {
                int num = va_arg(argc, int);
                _print_num(num);
            }
            break;
            
            case 'i': /*Handle decimal*/
            {
                double digit = va_arg(argc, double);
                _print_dec(digit);
            }
            break;

            default:
            _putchar('%');
            break;
            }

        }


    else 
        {
            _putchar(*format);
        }
    format++;
    }

    va_end(argc);
    return 0; /*CHANGE 2*/
}
