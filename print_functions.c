#include "main.h"

/**
 * print_char - function prints character
 * @ap: the pointer argument
 * @params: the parameters
 * Return: the printed number chars
 */
int print_char(va_list ap, params_t *params)
{
	char pad_character = ' ';
	unsigned int pad_number = 1, summation = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		summation += _putchar(ch);
	while (pad_number++ < params->width)
		summation += _putchar(pad_character);
	if (!params->minus_flag)
		summation += _putchar(ch);
	return (summation);
}

/**
 * print_int - function prints integer
 * @ap: the pointer argument
 * @params: the parameters
 * Return: the printed number chars
 */
int print_int(va_list ap, params_t *params)
{
	long longLen;

	if (params->l_modifier)
		longLen = va_arg(ap, long);
	else if (params->h_modifier)
		longLen = (short int)va_arg(ap, int);
	else
		longLen = (int)va_arg(ap, int);
	return (print_number(convert(longLen, 10, 0, params), params));
}

/**
 * print_string - function prints string
 * @ap: the pointer argument
 * @params: the parameters
 * Return: the printed number chars
 */
int print_string(va_list ap, params_t *params)
{
	char **string = va_arg(ap, char *), pad_character = ' ';
	unsigned int pad = 0, summation = 0, x = 0, y;

	(void)params;
	switch ((int)(!*string))
		case 1:
			*string = NULL_STRING;

	y = pad = _strlen(*string);
	if (params->precision < pad)
		y = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (x = 0; x < pad; x++)
				summation += _putchar(**string++);
		else
			summation += _puts(*string);
	}
	while (y++ < params->width)
		summation += _putchar(pad_character);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (x = 0; x < pad; x++)
				summation += _putchar(**string++);
		else
			summation += _puts(*string);
	}
	return (summation);
}

/**
 * print_percent - the prints string
 * @ap: the pointer argument
 * @params: the parameters
 * Return: the printed number chars
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - function that make a custom format specifier
 * @ap: the pointer argument
 * @params: the parameters
 * Return: the printed number chars
 */
int print_S(va_list ap, params_t *params)
{
	char *string = va_arg(ap, char *);
	char *hex;
	int summation = 0;

	if ((int)(!string))
		return (_puts(NULL_STRING));
	for (; *string; string++)
	{
		if ((*string > 0 && *string < 32) || *string >= 127)
		{
			summation += _putchar('\\');
			summation += _putchar('x');
			hex = convert(*string, 16, 0, params);
			if (!hex[1])
				summation += _putchar('0');
			summation += _puts(hex);
		}
		else
		{
			summation += _putchar(*string);
		}
	}
	return (summation);
}
