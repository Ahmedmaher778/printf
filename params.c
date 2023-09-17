#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @params: parameters struct
 * @az: argument pointer
 *
 * Return: void
*/

void init_params(params_r *params, va_list az)
{
	params->unsgn = 0;

	params->pl_flag = 0;
	params->sp_flag = 0;
	params->hash_flag = 0;
	params->z_flag = 0;
	params->m_flag = 0;

	params->wid = 0;
	params->precision = UINT_MAX;

	params->g_modifier = 0;
	params->j_modifier = 0;
	(void)az;
}

