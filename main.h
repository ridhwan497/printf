#ifndef _MAIN_H_
#define _MAIN_H_

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/*Defining Macros*/
#define BUFFER_SIZE 1024

/*FLAGS MACROS*/
#define INITIALIZE_FLAGS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define LOWERCASE 1
#define UPPERCASE 0
#define UNSIGNED 2
#define HEX_LOWER 3
#define HEX_UPPER 4
#define NULL_S "(null)"

/*MODIFIERS MACROS*/
#define HH 1
#define H 2
#define L 3
#define LL 4

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
 * @specifier: flag for specifier
 * @height: flag for height
 * @unsign: flag for unsigned
 * @modifier: flag for modifier
 */

typedef struct flags
{
	unsigned int width;
	unsigned int precision;

	unsigned int length :1;
	unsigned int height :1;

	unsigned int plus :1;
	unsigned int space :1;
	unsigned int hash :1;
	unsigned int zero :1;
	unsigned int minus :1;
	unsigned int unsign :1;
	unsigned int modifier : 3; 
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
int _printf(const char *format, ...);
int _putchar(int c);
int puts_str(char *str);
char *convert_num(long int number, int base, flags_t *flags, int parameters);
int unsigned_num(va_list args, flags_t *flags);
int print_address(va_list args, flags_t *flags);
int print_string(va_list args, flags_t *flags);
int print_integer(va_list args, flags_t *flags);
int print_ch(va_list args, flags_t *flags);
int print_string(va_list args, flags_t *flags);
int print_percent(va_list args, flags_t *flags);
int print_custom(va_list args, flags_t *flags);
void initialize_flags(flags_t *flags, va_list args);
char *get_precision(char *ptr, flags_t *flags, va_list args);
int print_octal_number(va_list args, flags_t *flags);
int print_hex_lowercase(va_list args, flags_t *flags);
int print_hex_uppercase(va_list args, flags_t *flags);
int print_binary(va_list args, flags_t *flags);
int print_num_op(char *str, flags_t *flags);
int print_left(char *str, flags_t *flags);
int print_right(char *str, flags_t *flags);
int print_range(char *begin, char *end, char *excempt);
int print_pointer(va_list args, flags_t *flags);
int print_reverse(va_list args, flags_t *flags);
int print_rot13(va_list args, flags_t *flags);
int (*handle_format_specifier(char *ptr))(va_list args, flags_t *flags);
int format_function(char *ptr, va_list arg, flags_t *flags);
char *get_modifier(char *ptr, flags_t *flags);
int print_flags(flags_t *flags, char *str);
char *get_width(char *ptr, flags_t *flags, va_list arg);
int _isdigit(int c);

#endif /* _MAIN_H_ */
