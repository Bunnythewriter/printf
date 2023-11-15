#include <unistd.h>
/**
* _putchar function to print characters
* @c: charcter variable
* Return: The character
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
