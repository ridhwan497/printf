#include "main.h"

/**
*initialize_flags - initializes flags struct
* it also resets the buffer
* @flags: struct flags
* @args: argument passed
*/

void initialize_flags(flags_t *flags, va_list args)
{
	flags->length = 0;
	flags->height = 0;

	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;

	flags->width = 0;
	flags->precision = UINT_MAX; /*defined in limits.h*/
	(void)args;
}
