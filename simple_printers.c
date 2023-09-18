#include "main.h"

/**
 * print_from_to - function prints a range of char
 * @start: the beginning address
 * @stop: the stop address
 * @except: the excepted address
 * Return: the number of bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int summation = 0;

	while (start <= stop)
	{
		if (start != except)
			summation += _putchar(*start);
		start++;
	}
	return (summation);
}

/**
 * print_rev - function prints in reverse string
 * @ap: is a string
 * @params: the parameters
 * Return: the number of bytes printed
 */
int print_rev(va_list ap, params_t *params)
{
	int length, summation = 0;
	char *string = va_arg(ap, char *);
	(void)params;

	if (string)
	{
		for (length = 0; *string; string++)
			length++;
		string--;
		for (; length > 0; length--, string--)
			summation += _putchar(*string);
	}
	return (summation);
}

/**
 * print_rot13 - function prints string
 * @ap: is a string
 * @params: the parameters
 * Return: the number of bytes printed
 */
int print_rot13(va_list ap, params_t *params)
{
	int x, i;
	int counter = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	x = 0;
	i = 0;
	while (a[x])
	{
		if ((a[x] >= 'A' && a[x] <= 'Z')
		    || (a[x] >= 'a' && a[x] <= 'z'))
		{
			i = a[x] - 65;
			counter += _putchar(array[i]);
		}
		else
			counter += _putchar(a[x]);
		x++;
	}
	return (counter);
}

