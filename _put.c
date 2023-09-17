#include "main.h"

/**
 * _puts - prints string with newline
 * @str: string to print
 *
 * Return: void
*/

int _puts(char *str)
{
	char *d = str;

	while (*str)
		_putchar(*str++);
	return (str - d);
}

/**
 * _putchar - writes the character c to stdout
 * @x: character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
*/

int _putchar(int x)
{
	static int l;
	static char buf[OUTPUT_BUF_SIZE];

	if (x == BUF_FLUSH || l >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, l);
		l = 0;
	}
	if (x != BUF_FLUSH)
		buf[l++] = x;
	return (1);
}

