#ifndef _MAIN_H_
#define _MAIN_H_
/**
 * File: main.h
 * 
 * Description: this file contains all the prototypes used in the printf repository
 * created by rafmury and ridhwan497
 */

/*include headers*/
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/*Defining macros*/
#define BUFFER_SIZE 1024

/*Flag Modifiers*/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_SPACE 8
#define F_HASH 16

/*Length Modifiers*/
#define L_H 1
#define L_L 2
#define L_LL 4

/*Prototypes*/

int _putchar(char c); /*writes the character c to stdout*/
int _printf(const char *format, ...); /*custom printf function*/
int print_string(va_list arg, const char specifier);/*s, c and %*/
int print_number(va_list arg, const char specifier); /*prints an integer*/
int print_binary(unsigned long int n); /*prints the binary representation of a number*/
int print_unsigned(unsigned int n, int base, char uppercase);/*prints an unsigned integer*/
int get_flags(const char *format, int *q); /*gets the flags*/
int get_length(const char *format, int *q); /*gets the length mod*/
int get_width(const char *format, int *q); /*gets the width*/
int get_precision(const char *format, int *q); /*gets the precision*/
int print_rot13(char *str); /*prints a string in rot13*/

#endif
