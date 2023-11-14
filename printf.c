#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _print_char(char c)
{
    while (c != '\0') {
        _putchar(c);}
        c++;
    return 0; /*change 0*/
}

int _print_string(const char *format) {
    int cc = 0;
    while (*format != '\0') {
        cc += _putchar(*format);
        format++;
        cc++;
    }
    return cc;
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
        return 1; /*CHANGE 1*/
    
}

int _print_dec(double n)
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
    return 1;
}

int _printf(const char *format, ...)
{
    int cs = 0;
    va_list argc;
    va_start(argc, format);
    
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
                    cs += _putchar(sc);
                }
                break;
                
            case 's': /*handle string*/
                {
                    char *format = va_arg(argc, char *);
                    cs += _print_string(format);
                }
                break;

            case 'd': /*Handle integer*/
            {
                int num = va_arg(argc, int);
                cs += _print_num(num);
            }
            break;
            
            case 'i': /*Handle decimal*/
            {
                double digit = va_arg(argc, double);
                cs += _print_dec(digit);
            }
            break;

            default:
            _putchar('%');
            break;
            }

        }


    else 
        {
            cs += write(1, format, 1);
        }
    format++;
    }

    va_end(argc);
    return cs; /*CHANGE 2*/
}
