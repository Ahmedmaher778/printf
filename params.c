#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @params: parameters struct
 * @az: argument pointer
 *
 * Return: void
*/

void init_params(params_t *params, va_list az)
{
	params->unsgn = 0;

	params->pl_flag = 0;
	params->sp_flag = 0;
	params->hash_flag = 0;
	params->z_flag = 0;
	params->m_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)az;
}

