#include "main.h"

/**
 * _printf - prints function
 * @format: format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	int summation = 0;
	char *p, *beginning;
	va_list az;
	params_t params = PARAMS_INIT;

	va_start(az, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, az);
		if (*p != '%')
		{
			summation += _putchar(*p);
			continue;
		}
		beginning = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, az);
		p = get_precision(p, &params, az);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			summation += print_from_to(beginning, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			summation += get_print_func(p, az, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(az);
	return (summation);
}
