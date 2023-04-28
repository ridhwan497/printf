![image](https://user-images.githubusercontent.com/126829982/235145391-61e0761b-7c79-4bda-a9ed-08a0dad31a87.png)

Project files

main.h : Include all function prototypes and structure of specifiers

_printf.c : This code defines a function called _printf, which takes a format string and optional arguments and produces output according to the format string. The function iterates over the format string, parsing it for format specifiers (beginning with a '%') and handling each one according to its type. It uses a buffer to store the output and writes to the standard output when the buffer is full or when the iteration is complete. The function returns the total number of characters printed.

flags.c : This code  parses a formatted string (passed as the format parameter) and extract any active flags used in the string. The function starts by initializing flags to zero and setting curr_i to the value pointed to by i plus one.

get_precision.c : This code defines a function named `get_precision` that takes three parameters: a `const char*` `format`, an `int*` `i`, and a `va_list` `list`. The function calculates the precision for printing by parsing the format string starting at position `*i` and returns it as an `int`. The precision is determined by looking for a period '.' character in the format string, followed by either a '*' character indicating a variable argument passed through `va_list list`, or by a series of digits representing the precision. The function updates the value of `*i` to the last position it read from the format string.

get_size : The purpose of the function is to determine the size to cast an argument based on the format specifier in the format string. It looks for the characters 'l' or 'h' immediately after the format specifier and sets the size accordingly.

get_width.c : Calculates the width for printing by iterating over the format string, extracting the width if it is specified explicitly in the format string, or extracting the width from the list of arguments if it is specified using a * in the format string. Finally, it updates the i value to skip over the width specifier in the format string and returns the extracted width value.

handle_print.c :  Handles printing of different types of arguments in a formatted string. It takes in several parameters such as the formatted string to print (fmt), an index pointer (ind), a list of arguments to print (list), a buffer to store the printed output (buffer), active flags (flags), width specification (width), precision specification (precision), and size specifier (size).

handlers.c : This is a program that includes several functions to handle printing of characters, numbers, and unsigned numbers with specific format specifiers. The program contains comments describing each function and its parameters, as well as its expected return value.

print_functions.c : This code defines a set of functions that can be used to print formatted output to the console. It includes functions to print characters, strings, integers, and binary numbers, as well as a function to print a percent sign.

utils.c : This is a C code file that includes a set of functions. Here is a brief explanation of each function:

1. `is_printable(char c)`: This function takes a character `c` and evaluates if it is printable. It returns 1 if `c` is printable and 0 otherwise.

2. `append_hexa_code(char ascii_code, char buffer[], int i)`: This function appends the ASCII code of a character `ascii_code` to a buffer `buffer` in hexadecimal format starting at index `i`. The function returns the value 3.

3. `is_digit(char c)`: This function takes a character `c` and verifies if it is a digit. It returns 1 if `c` is a digit and 0 otherwise.

4. `convert_size_number(long int num, int size)`: This function takes a number `num` and casts it to the specified size `size`. If `size` is `S_LONG`, it returns the `num` as is. If `size` is `S_SHORT`, it casts `num` to a `short`. Otherwise, it casts `num` to an `int`.

5. `convert_size_unsgnd(unsigned long int num, int size)`: This function takes an unsigned number `num` and casts it to the specified size `size`. If `size` is `S_LONG`, it returns the `num` as is. If `size` is `S_SHORT`, it casts `num` to an `unsigned short`. Otherwise, it casts `num` to an `unsigned int`.

The file includes the header file `main.h`. The header file likely includes declarations for these functions and any necessary libraries.
