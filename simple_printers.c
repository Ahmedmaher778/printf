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
	int i, inde;
	int counter = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	inde = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			inde = a[i] - 65;
			counter += _putchar(array[inde]);
		}
		else
			counter += _putchar(a[i]);
		i++;
	}
	return (counter);
}
