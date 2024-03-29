#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUF_FLUSH -1
#define OUTPUT_BUF_SIZE 1024

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_UNSIGNED	2
#define CONVERT_LOWERCASE	1

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @l_modifier: on if l_modifier is specified
 * @h_modifier: on if h_modifier is specified
 *
 * @precision: field precision specified
 * @width: field width specified
 *
 * @space_flag: on if hashtag_flag specified
 * @plus_flag: on if plus_flag specified
 * @zero_flag: on if _flag specified
 * @hashtag_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 */
typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int l_modifier		: 1;
	unsigned int h_modifier		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int space_flag		: 1;
	unsigned int plus_flag		: 1;
	unsigned int zero_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int minus_flag		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c module */
int _putchar(int c);
int _puts(char *str);

/* print_functions.c module */
int print_int(va_list ap, params_t *params);
int print_char(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* number.c module */
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);
char *convert(long int num, int base, int flags, params_t *params);

/* specifier.c module */
int get_print_func(char *s, va_list ap, params_t *params);
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);
int get_flag(char *s, params_t *params);

/* convert_number.c module */
int print_HEX(va_list ap, params_t *params);
int print_hex(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);

/* simple_printers.c module */
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);
int print_from_to(char *start, char *stop, char *except);

/* print_number.c module */
int _strlen(char *s);
int _isdigit(int c);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);
int print_number(char *str, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list ap);

/* string_fields.c modoule */
char *get_precision(char *p, params_t *params, va_list ap);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif
