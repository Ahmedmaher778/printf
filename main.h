#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsgn: flag if unsigned value
 *
 * @pl_flag: on if plus_flag specified
 * @sp_flag: on if hashtag_flag specified
 * @hash_flag: on if _flag specified
 * @z_flag: on if _flag specified
 * @m_flag: on if _flag specified
 *
 * @wid: field width specified
 * @precision: field precision specified
 *
 * @g_modifier: on if g_modifier is specified
 * @j_modifier: on if j_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsgn			: 1;

	unsigned int pl_flag		: 1;
	unsigned int sp_flag		: 1;
	unsigned int hash_flag	: 1;
	unsigned int z_flag		: 1;
	unsigned int m_flag		: 1;

	unsigned int wid;
	unsigned int precision;

	unsigned int g_modifier		: 1;
	unsigned int j_modifier		: 1;
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
} specifier_r;

/* _put.c module */
int _puts(char *str);
int _putchar(int x);

/* print_functions.c module */
int print_char(va_list az, params_t *params);
int print_int(va_list az, params_t *params);
int print_string(va_list az, params_t *params);
int print_percent(va_list az, params_t *params);
int print_S(va_list az, params_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list az, params_t *params);
int print_address(va_list az, params_t *params);

/* specifier.c module */
int (*get_specifier(char *s))(va_list az, params_t *params);
int get_print_func(char *s, va_list az, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list az);

/* convert_number.c module */
int print_hex(va_list az, params_t *params);
int print_HEX(va_list az, params_t *params);
int print_binary(va_list az, params_t *params);
int print_octal(va_list az, params_t *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list az, params_t *params);
int print_rot13(va_list az, params_t *params);

/* print_number.c module */
int _isdigit(int x);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list az);

/* string_fields.c modoule */
char *get_precision(char *b, params_t *params, va_list az);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif

