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
	unsigned int pad = 1, summation = 0, x = va_arg(ap, int);

	if (params->minus_flag)
		summation += _putchar(x);
	while (pad++ < params->width)
		summation += _putchar(pad_character);
	if (!params->minus_flag)
		summation += _putchar(x);
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
	long len;

	if (params->l_modifier)
		len = va_arg(ap, long);
	else if (params->h_modifier)
		len = (short int)va_arg(ap, int);
	else
		len = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - function prints string
 * @ap: the pointer argument
 * @params: the parameters
 * Return: the printed number chars
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, summation = 0, i = 0, x;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	x = pad = _strlen(str);
	if (params->precision < pad)
		x = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				summation += _putchar(*str++);
		else
			summation += _puts(str);
	}
	while (x++ < params->width)
		summation += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				summation += _putchar(*str++);
		else
			summation += _puts(str);
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
	char *str = va_arg(ap, char *);
	char *hex;
	int summation = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			summation += _putchar('\\');
			summation += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				summation += _putchar('0');
			summation += _puts(hex);
		}
		else
		{
			summation += _putchar(*str);
		}
	}
	return (summation);
}
