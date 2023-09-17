#include "main.h"

/**
 * _printf - prints function
 * @format: format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	int summation = 0;
	char *b, *beginning;
	va_list az;
	params_r params = PARAMS_INIT;

	va_start(az, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (b = (char *)format; *b; b++)
	{
		init_params(&params, az);
		if (*b != '%')
		{
			summation += _putchar(*b);
			continue;
		}
		beginning = b;
		b++;
		while (get_flag(b, &params))
		{
			b++;
		}
		b = get_width(b, &params, az);
		b = get_precision(b, &params, az);
		if (get_modifier(b, &params))
			b++;
		if (!get_specifier(b))
			summation += print_from_to(beginning, b,
				params.j_modifier || params.g_modifier ? b - 1 : 0);
		else
			summation += get_print_func(b, az, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(az);
	return (summation);
}
