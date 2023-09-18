#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: format string
 * Return: number of bytes printed
*/

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int l = 0;

	while (specifiers[l].specifier)
	{
		if (*s == specifiers[l].specifier[0])
		{
			return (specifiers[l].f);
		}
		l++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format func
 * @s: format string
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: the number of bytes printed
*/

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @s: format string
 * @params: parameters struct
 * Return: if flag was valid
*/

int get_flag(char *s, params_t *params)
{
	int l = 0;

	switch (*s)
	{
		case '#':
			l = params->hashtag_flag = 1;
			break;
		case '0':
			l = params->zero_flag = 1;
			break;
		case '+':
			l = params->plus_flag = 1;
			break;
		case '-':
			l = params->minus_flag = 1;
			break;
		case ' ':
			l = params->space_flag = 1;
			break;
	}
	return (l);
}

/**
 * get_modifier - finds the modifier func
 * @s: format string
 * @params: parameters struct
 * Return: if modifier was valid
*/

int get_modifier(char *s, params_t *params)
{
	int l = 0;

	switch (*s)
	{
	case 'l':
		l = params->l_modifier = 1;
		break;
	case 'h':
		l = params->h_modifier = 1;
		break;
	}
	return (l);
}

/**
 * get_width - gets the width from the format string
 * @s: format string
 * @params: parameters struct
 * @ap: argument pointer
 * Return: new pointer
*/

char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}


