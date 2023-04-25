#ifndef _MAIN_H_
#define _MAIN_H_

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/*Defining Macros*/
#define BUFFER_SIZE 1024
#define NULL_S "(null)"

#define FLUSH -1 /*Flushes the buffer*/
#define FIELD_SIZE 50 /*Size of the field of buffer size*/

/*FLAGS MACROS*/
#define FLAGS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define LOWERCASE	1
#define UNSIGNED	2

/*Structs*/

/**
 * struct flags - struct for flags
 * @plus: flag for plus
 * @space: flag for space
 * @hash: flag for hash
 * @zero: flag for zero
 * @minus: flag for minus
 * @width: flag for width
 * @precision: flag for precision
 * @length: flag for length
 * @height: flag for height
 * @unsign: flag for unsigned
 */

typedef struct flags
{
	unsigned int width;
	unsigned int precision;

	unsigned int length		:1;
	unsigned int height		:1;

	unsigned int plus		:1;
	unsigned int space		:1;
	unsigned int hash		:1;
	unsigned int zero		:1;
	unsigned int minus		:1;
	unsigned int unsign		:1;

} flags_t;

/**
 * struct print - struct for printing
 * @c: char to print
 * @f: function to print
 */

typedef struct print
{
	char *c;
	int (*f)(va_list, flags_t *);
} print_t;

/* Prototypes */

/* file: _putchar.c */
int _putchar(int c);
int puts_str(char *s);

/* file: flags.c */
void initialize_flags(flags_t *flags, va_list args);

/*file: get_precision.c*/
char *get_precision(char *ptr, flags_t *flags, va_list args);

/*file: handle_fs.c*/
int (*handle_format_specifier(char *ptr))(va_list args, flags_t *flags);
int format_function(char *ptr, va_list arg, flags_t *flags);
int get_modify(char *ptr, flags_t *flags);
int print_flags(char *str, flags_t *flags);
char *get_width(char *ptr, flags_t *flags, va_list arg);

/*file: number_converter.c*/
char *convert_num(long int number, int base, int parameters, flags_t *flags);
int unsigned_num(va_list args, flags_t *flags);
int print_address(va_list args, flags_t *flags);

/*file: print_functions.c*/
int print_integer(va_list args, flags_t *flags);
int print_ch(va_list args, flags_t *flags);
int print_string(va_list args, flags_t *flags);
int print_percent(va_list arg, flags_t *flags);
int print_custom(va_list args, flags_t *flags);

/*file: print_no_option*/
int _strlen(char *str);
int _isdigit(int ch);
int print_num_op(char *str, flags_t *flags);
int print_left(char *str, flags_t *flags);
int print_right(char *str, flags_t *flags);

/*file: print_num.c*/
int print_octal_number(va_list args, flags_t *flags);
int print_hex_lowercase(va_list args, flags_t *flags);
int print_hex_uppercase(va_list args, flags_t *flags);
int print_binary(va_list args, flags_t *flags);

/*file: print_pointer.c*/
int print_range(char *begin, char *end, char *excempt);
int print_reverse(va_list args, flags_t *flags);
int print_rot13(va_list args, flags_t *flags);

/* file: _printf.c */
int _printf(const char *format, ...);

#endif /* _MAIN_H_ */
