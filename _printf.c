#include <stdarg.h>
#include <unistd.h>

<<<<<<< HEAD
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
=======
int _putchar(char c) {
    return write(1, &c, 1);
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    char c;

    while ((c = *format) != '\0') {
        if (c == '%') {
            c = *(++format); // Move to the next character after '%'
            switch (c) {
                case 'c':
                    // Print a single character
                    _putchar(va_arg(args, int));
                    count++;
                    break;
                case 's': {
                    // Print a string
                    char *str = va_arg(args, char *);
                    while (*str != '\0') {
                        _putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    // Print a literal '%'
                    _putchar('%');
                    count++;
                    break;
                default:
                    // Unknown specifier, just print it as is
                    _putchar('%');
                    _putchar(c);
                    count += 2;
            }
        } else {
            // Regular character, just print it
            _putchar(c);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}

int main() {
    _printf("Hello, %s! You are %c%% awesome.\n", "World", '42');
    return 0;
>>>>>>> 3fc46be7881c920dc181310e1e4695bab19fb5f7
}
