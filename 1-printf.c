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
