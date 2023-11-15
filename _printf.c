#include "main.h"
/**
 * _printf - a function that produces output according to format
 * @format: the format character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int lets_print = 0;
	va_list arguments;

	if (format == NULL)
		return (-1);
	va_start(arguments, format);
	while (*format)
	{
		if (*format != '%')
			write(1, format, 1);
			lets_print++;
		else
		{
			format++;
			if (*format == '\0')
			break;
			if (*format == '%')
				write(1, format, 1);
				lets_print++;
			else if (*format == 'c')
			char c = va_arg(arguments, char);

			write(1, &c, 1);
			lets_print++;
			else if (*format == 's')
			{
			char *str = va_arg(arguments, char*);
			int length = 0;

			while (str(length) != '\0')
			length++;

			write(1, str, length);
			lets_print += length;
			}
		}
		format++;
	}
	va_end(arguments);
	return (lets_print);
}
