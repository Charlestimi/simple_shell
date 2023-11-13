#include "shell_main.h"

/**
 * our_printf - user defined printf function to print strings
 * @str: pointer to the string
 *
 */

void our_printf(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
	/* or write(1, &our_str, 1/strlen(our_str)); */
}



/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
