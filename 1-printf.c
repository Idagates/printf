#include "main.h"
#include <stdio.h>

/**
 * print_string - a function that prints a strings
 * @str: the string to print
 * Return: the number of string
 */

int print_string(char *str)
{
	int length = 0;

	while (*str != '\0')
	{
		write(1, &*str, 1);
		str++;
		length++;
	}
	return (length);
}

/**
 * print_int - prints an integer
 * @n: the integer to print
 * Return: an integer
 */
int print_int(int n)
{
	char digit;
	int length = 0;
	char buffer[20];
	int index = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		length++;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		digit = '0' + (n % 10);
		buffer[index++] = digit;
		n /= 10;
		length++;
	}
	while (index > 0)
	{
		write(1, &buffer[--index], 1);
	}
	return (length);
}

/**
 * _printf - a function that produces output according to format
 * @format: the format character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int lets_print = 0;
	va_list arguments;

	va_start(arguments, format);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char s = va_arg(arguments, int);

				lets_print += write(1, &s, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(arguments, char*);

				lets_print += print_string(str);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int number = va_arg(arguments, int);

				lets_print += print_int(number);
			}
			else
			{
				return (-1);
			}
		}
		else
		{
		write(1, format, 1);
		lets_print++;
		}
	}
	va_end(arguments);
	return (lets_print);
}
