#include "main.h"

/**
 * print_char - function prints character
 * @az: the pointer argument
 * @params: the parameters
 * Return: the printed number chars
 */
int print_char(va_list az, params_t *params)
{
	char pad_character = ' ';
	unsigned int pad_number = 1, summation = 0, character = va_arg(az, int);

	if (params->m_flag)
		summation += _putchar(character);
	while (pad_number++ < params->width)
		summation += _putchar(pad_character);
	if (!params->m_flag)
		summation += _putchar(character);
	return (summation);
}

/**
 * print_int - function prints integer
 * @az: the pointer argument
 * @params: the parameters
 * Return: the printed number chars
 */
int print_int(va_list az, params_t *params)
{
	long len;

	if (params->l_modifier)
		len = va_arg(az, long);
	else if (params->h_modifier)
		len = (short int)va_arg(az, int);
	else
		len = (int)va_arg(az, int);
	return (print_number(convert(len, 10, 0, params), params));
}

/**
 * print_string - function prints string
 * @az: the pointer argument
 * @params: the parameters
 * Return: the printed number chars
 */
int print_string(va_list az, params_t *params)
{
	char *string = va_arg(az, char *), pad_character = ' ';
	unsigned int pad = 0, summation = 0, x = 0, y;

	(void)params;
	switch ((int)(!string))
		case 1:
			string = NULL_STRING;

	y = pad = _strlen(string);
	if (params->precision < pad)
		y = pad = params->precision;

	if (params->m_flag)
	{
		if (params->precision != UINT_MAX)
			for (x = 0; x < pad; x++)
				summation += _putchar(*string++);
		else
			summation += _puts(string);
	}
	while (y++ < params->width)
		summation += _putchar(pad_character);
	if (!params->m_flag)
	{
		if (params->precision != UINT_MAX)
			for (x = 0; x < pad; x++)
				summation += _putchar(*string++);
		else
			summation += _puts(string);
	}
	return (summation);
}

/**
 * print_percent - the prints string
 * @az: the pointer argument
 * @params: the parameters
 * Return: the printed number chars
 */
int print_percent(va_list az, params_t *params)
{
	(void)az;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - function that make a custom format specifier
 * @az: the pointer argument
 * @params: the parameters
 * Return: the printed number chars
 */
int print_S(va_list az, params_t *params)
{
	char *string = va_arg(az, char *);
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
