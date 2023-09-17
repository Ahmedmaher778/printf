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
 * @az: is a string
 * @params: the parameters
 * Return: the number of bytes printed
 */
int print_rev(va_list az, params_r *params)
{
	int length, summation = 0;
	char *string = va_arg(az, char *);
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
 * @az: is a string
 * @params: the parameters
 * Return: the number of bytes printed
 */
int print_rot13(va_list az, params_r *params)
{
	int x, index, counter = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(az, char *);
	(void)params;

	index = 0;
	x = 0;
	while (a[x])
	{
		if ((a[x] >= 'A' && a[x] <= 'Z')
		    || (a[x] >= 'a' && a[x] <= 'z'))
		{
			index = a[x] - 65;
			counter += _putchar(array[index]);
		}
		else
			counter += _putchar(a[x]);
		x++;
	}
	return (counter);
}
