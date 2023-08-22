#include <stdarg.h>
#include <unistd.h>

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
}
